<?php
/**
 * @file
 * pw_subsite.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function pw_subsite_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_description';
  $context->description = '';
  $context->tag = 'blog';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'blog:page_1' => 'blog:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-11' => array(
          'module' => 'block',
          'delta' => '11',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('blog');
  $export['blog_description'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'donations';
  $context->description = 'adds blocks';
  $context->tag = 'PW page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/10508' => 'node/10508',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
        'block-30' => array(
          'module' => 'block',
          'delta' => '30',
          'region' => 'content',
          'weight' => '-8',
        ),
        'block-32' => array(
          'module' => 'block',
          'delta' => '32',
          'region' => 'sidebar_second',
          'weight' => '76',
        ),
        'block-71' => array(
          'module' => 'block',
          'delta' => '71',
          'region' => 'sidebar_second',
          'weight' => '78',
        ),
        'block-14' => array(
          'module' => 'block',
          'delta' => '14',
          'region' => 'sidebar_second',
          'weight' => '80',
        ),
        'block-31' => array(
          'module' => 'block',
          'delta' => '31',
          'region' => 'sidebar_second',
          'weight' => '96',
        ),
        'block-29' => array(
          'module' => 'block',
          'delta' => '29',
          'region' => 'sidebar_second',
          'weight' => '82',
        ),
        'views-pw_donations_recent-recent' => array(
          'module' => 'views',
          'delta' => 'pw_donations_recent-recent',
          'region' => 'sidebar_second',
          'weight' => '86',
        ),
        'views-pw_donation_state-block' => array(
          'module' => 'views',
          'delta' => 'pw_donation_state-block',
          'region' => 'sidebar_second',
          'weight' => '88',
        ),
        'block-47' => array(
          'module' => 'block',
          'delta' => '47',
          'region' => 'sidebar_second',
          'weight' => '84',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('PW page');
  t('adds blocks');
  $export['donations'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'kuratorium';
  $context->description = '';
  $context->tag = 'PW page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'ueber-uns/mehr/kuratorium' => 'ueber-uns/mehr/kuratorium',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-Trustees-block_1' => array(
          'module' => 'views',
          'delta' => 'Trustees-block_1',
          'region' => 'content',
          'weight' => '-9',
        ),
        'webform-client-block-6578' => array(
          'module' => 'webform',
          'delta' => 'client-block-6578',
          'region' => 'content',
          'weight' => '-8',
        ),
        'block-17' => array(
          'module' => 'block',
          'delta' => '17',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'block-14' => array(
          'module' => 'block',
          'delta' => '14',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('PW page');
  $export['kuratorium'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'press_contact';
  $context->description = '';
  $context->tag = 'press';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*/press' => '*/press',
        '*/press/*' => '*/press/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'block-9' => array(
          'module' => 'block',
          'delta' => '9',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('press');
  $export['press_contact'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'press_sidebar';
  $context->description = '';
  $context->tag = 'press';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*/press' => '*/press',
        '*/press/*' => '*/press/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-10' => array(
          'module' => 'block',
          'delta' => '10',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-blog-block_1' => array(
          'module' => 'views',
          'delta' => 'blog-block_1',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('press');
  $export['press_sidebar'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pw_premium_promo';
  $context->description = 'Adds a block with information to the premium profile to the user edit form';
  $context->tag = 'profiles';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user/*/edit' => 'user/*/edit',
      ),
    ),
    'php' => array(
      'values' => array(
        0 => TRUE,
      ),
      'options' => array(
        'phpcode' => 'global $user;
$is_premium_user = array_search(\'Premium User\', $user->roles)?true:false;
return !$is_premium_user;',
      ),
    ),
    'user' => array(
      'values' => array(
        'Candidate' => 'Candidate',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-38' => array(
          'module' => 'block',
          'delta' => '38',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds a block with information to the premium profile to the user edit form');
  t('profiles');
  $export['pw_premium_promo'] = $context;

  return $export;
}
