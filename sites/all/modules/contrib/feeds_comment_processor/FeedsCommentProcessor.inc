<?php

/**
 * @file
 * Class definition of FeedsCommentProcessor.
 */

// Create or delete FEEDS_COMMENT_BATCH_SIZE at a time.
define('FEEDS_COMMENT_BATCH_SIZE', 50);

// Deprecated. Use FEEDS_SKIPE_EXISTING, FEEDS_REPLACE_EXISTNG,
// FEEDS_UPDATE_EXISTING instead.
define('FEEDS_COMMENT_SKIP_EXISTING', 0);
define('FEEDS_COMMENT_REPLACE_EXISTING', 1);
define('FEEDS_COMMENT_UPDATE_EXISTING', 2);

/**
 * Creates comments from feed items.
 */
class FeedsCommentProcessor extends FeedsProcessor {
  /**
   * Define entity type.
   */
  public function entityType() {
    return 'comment';
  }

  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('Comments');
    return $info;
  }

  /**
   * Creates a new comment in memory and returns it.
   */
  protected function newEntity(FeedsSource $source) {
    $comment = new stdClass();
    $comment->cid = 0;
    $comment->pid = 0;
    $comment->uid = $this->config['author'];
    $account = user_load($comment->uid);
    $comment->mail = $account->mail;
    $comment->name = $account->name;
    $comment->hostname = '127.0.0.1';
    $comment->created = FEEDS_REQUEST_TIME;
    $comment->is_anonymous = 0;
    $comment->status = 0;
    $comment->language = LANGUAGE_NONE;
    $comment->comment_body[$comment->language][0]['format'] = $this->config['input_format'];
    $comment->feeds_comment_item = new stdClass();
    $comment->feeds_comment_item->id = $this->id;
    $comment->feeds_comment_item->imported = FEEDS_REQUEST_TIME;
    $comment->feeds_comment_item->feed_nid = $source->feed_nid;
    $comment->feeds_comment_item->guid = '';
    return $comment;
  }

  /**
   * Loads an existing comment.
   */
  protected function entityLoad(FeedsSource $source, $cid) {
    return comment_load($cid);
  }

  /**
   * Validates a comment.
   */
  protected function entityValidate($comment) {
    if (empty($comment->nid)) {
      throw new FeedsValidationException(t('Unable to create comment with empty NID.'));
    }
  }

  /**
   * Save a comment.
   */
  public function entitySave($comment) {
    // comment_submit() overrides the created and changed properties.
    $created = $comment->created;
    comment_submit($comment);
    $comment->created = $created;
    $comment->changed = $created;

    comment_save($comment);
  }

  /**
   * Delete multiple comments.
   */
  protected function entityDeleteMultiple($cids) {
    comment_delete_multiple($cids);
  }

  /**
   * Implement expire().
   */
  public function expire($time = NULL) {
    if ($time === NULL) {
      $time = $this->expiryTime();
    }
    if ($time == FEEDS_EXPIRE_NEVER) {
      return;
    }
    $result = db_query_range("SELECT c.cid FROM {comment} c INNER JOIN {feeds_comment_item} fci ON c.cid = fci.cid WHERE fci.id = :id AND c.created < :timestamp", 0, variable_get('feeds_comment_batch_size', FEEDS_COMMENT_BATCH_SIZE), array(':id' => $this->id, ':timestamp' => FEEDS_REQUEST_TIME - $time));
    while ($comment = db_fetch_object($result)) {
      comment_delete($comment->cid);
    }
    if (db_result(db_query_range("SELECT c.cid FROM {comment} c INNER JOIN {feeds_comment_item} fci ON c.cid = fci.cid WHERE fci.id = :id AND c.created < :timestamp", 0, 1, array(':id' => $this->id, ':timestamp' => FEEDS_REQUEST_TIME - $time)))) {
      return FEEDS_BATCH_ACTIVE;
    }
    return FEEDS_BATCH_COMPLETE;
  }

  /**
   * Return expiry time.
   */
  public function expiryTime() {
    return $this->config['expire'];
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    $node_types = node_type_get_names();
    $node_type = isset($node_types['article']) ? 'article' : key($node_types);

    return array(
      'node_type' => $node_type,
      'input_format' => filter_default_format(),
      'update_existing' => FEEDS_SKIP_EXISTING,
      'expire' => FEEDS_EXPIRE_NEVER,
      'mappings' => array(),
      'author' => 0,
    ) + parent::configDefaults();
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = array();

    $node_types = node_type_get_names();
    array_walk($node_types, 'check_plain');
    $form['node_type'] = array(
      '#type' => 'select',
      '#title' => t('Content type'),
      '#options' => $node_types,
      '#default_value' => $this->config['node_type'],
    );

    $format_options = array(filter_default_format() => t('Default format'));
    $formats = filter_formats();
    foreach ($formats as $format) {
      $format_options[$format->format] = $format->name;
    }
    $form['input_format'] = array(
      '#type' => 'select',
      '#title' => t('Input format'),
      '#description' => t('Select the input format for the comments to be created.'),
      '#options' => $format_options,
      '#default_value' => $this->config['input_format'],
    );

    $author = user_load($this->config['author']);
    $form['author'] = array(
      '#type' => 'textfield',
      '#title' => t('Author'),
      '#description' => t('Select the author of the comments to be created - leave empty to assign "anonymous".'),
      '#autocomplete_path' => 'user/autocomplete',
      '#default_value' => empty($author->name) ?  'anonymous' : check_plain($author->name),
    );

    $period = drupal_map_assoc(array(FEEDS_EXPIRE_NEVER, 3600, 10800, 21600, 43200, 86400, 259200, 604800, 604800 * 4, 604800 * 12, 604800 * 24, 31536000), 'feeds_format_expire');
    $form['expire'] = array(
      '#type' => 'select',
      '#title' => t('Expire comments'),
      '#options' => $period,
      '#description' => t('Select after how much time comments should be deleted. The comment\'s published date will be used for determining the comment\'s age, see Mapping settings.'),
      '#default_value' => $this->config['expire'],
    );

    $form['update_existing'] = array(
      '#type' => 'radios',
      '#title' => t('Update existing comments'),
      '#description' => t('Select how existing comments should be updated. Existing comments will be determined using mappings that are a "unique target".'),
      '#options' => array(
        FEEDS_SKIP_EXISTING => 'Do not update existing comments',
        FEEDS_REPLACE_EXISTING => 'Replace existing comments',
        FEEDS_UPDATE_EXISTING => 'Update existing comments (slower than replacing them)',
      ),
      '#default_value' => $this->config['update_existing'],
    );
    return $form;
  }

  /**
   * Override parent::configFormValidate().
   */
  public function configFormValidate(&$values) {
    if ($author = user_load_by_name($values['author'])) {
      $values['author'] = $author->uid;
    }
    else {
      $values['author'] = 0;
    }
  }

  /**
   * Override setTargetElement to operate on a target item that is a comment.
   */
  public function setTargetElement(FeedsSource $source, $target_comment, $target_element, $value) {
    switch ($target_element) {
      case 'nid_by_guid':
        $target_comment->nid = db_select('feeds_item', 'f')
          ->fields('f', array('entity_id'))
          ->condition('entity_type', 'node')
          ->condition('guid', $value)
          ->execute()
          ->fetchField();
        break;
      case 'guid':
        $target_comment->feeds_comment_item->guid = $value;
        break;
      case 'created':
        $target_comment->created = feeds_to_unixtime($value, REQUEST_TIME);
        break;
      default:
        parent::setTargetElement($source, $target_comment, $target_element, $value);
        break;
    }
  }

  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {
    $targets = array(
      'pid' => array(
        'name' => t('Parent ID'),
        'description' => t('The cid to which this comment is a reply.'),
      ),
      'nid' => array(
        'name' => t('Node ID'),
        'description' => t('The nid to which this comment is a reply.'),
      ),
      'nid_by_guid' => array(
        'name' => t('Node ID by GUID'),
        'description' => t('The node to which this comment is a reply, looked up by the GUID of a previous import.'),
      ),
      'uid' => array(
        'name' => t('User ID'),
        'description' => t('The Drupal user ID of the comment author.'),
      ),
      'subject' => array(
        'name' => t('Title'),
        'description' => t('The title of the comment.'),
      ),
      'hostname' => array(
        'name' => t('Hostname'),
        'description' => t('The author\'s host name.'),
      ),
      'created' => array(
        'name' => t('Published date'),
        'description' => t('The UNIX time when a comment has been saved.'),
      ),
      'status' => array(
        'name' => t('Published status'),
        'description' => t('The published status of a comment. (0 = Published, 1 = Not Published)'),
      ),
      'name' => array(
        'name' => t('Name'),
        'description' => t('The comment author\'s name.'),
      ),
      'mail' => array(
        'name' => t('Email'),
        'description' => t('The comment author\'s e-mail address.'),
      ),
      'homepage' => array(
        'name' => t('Homepage'),
        'description' => t('The comment author\'s home page address'),
      ),
      'guid' => array(
        'name' => t('GUID'),
        'description' => t('The external GUID of the comment. E. g. the feed item GUID in the case of a syndication feed. May be unique.'),
        'optional_unique' => TRUE,
      ),
    );

    // Let other modules expose mapping targets.
    self::loadMappers();
    feeds_alter('feeds_processor_targets', $targets, 'comment', 'comment_node_' . $this->config['node_type']);
    feeds_alter('feeds_comment_processor_targets', $targets);

    return $targets;
  }

  /**
   * Get cid of an existing feed item comment if available.
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    if ($cid = parent::existingEntityId($source, $result)) {
      return $cid;
    }

    // Iterate through all unique targets and test whether they do already
    // exist in the database.
    foreach ($this->uniqueTargets($source, $result) as $target => $value) {
      switch ($target) {
        case 'guid':
          $cid = db_query("SELECT cid FROM {feeds_comment_item} WHERE feed_nid = :feed_nid AND id = :id AND guid = :guid", array(':feed_nid' => $source->feed_nid, ':id' => $source->id, ':guid' => $value))->fetchField();
          break;
      }
      if ($cid) {
        // Return with the first cid found.
        return $cid;
      }
    }
    return 0;
  }
}