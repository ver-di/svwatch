<?php
/**
 * @file
 * pw_profiles.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function pw_profiles_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|default';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'candidate_full_name' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'candidate_social_links' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
        'field_delimiter' => '',
      ),
    ),
    'candidate_stats_questions_get' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
        'field_delimiter' => '',
      ),
    ),
    'candidate_tab_navigation' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
        'field_delimiter' => '',
      ),
    ),
    'name' => array(
      'weight' => '26',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_user_birthday' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'dt',
          'lb-col' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'dd',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_user_commitee' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'dt',
          'fi' => TRUE,
          'fi-el' => 'dd',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_user_constituency' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'dt',
          'lb-col' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'dd',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_user_fname' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'dt',
          'lb-col' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'dd',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_user_fraction' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'dt',
          'lb-col' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'dd',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_user_job_skills' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'dt',
          'lb-col' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'dd',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_user_list' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_user_list_position' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => '. Liste verdi, Platz ',
          'lb-el' => 'span',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_user_lname' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'dt',
          'lb-col' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'dd',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_user_picture' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'candidate-detail-image',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_user_picture_copyright' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'figcaption',
          'ow-cl' => 'text-right small',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_user_political_roles' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'dt',
          'lb-col' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'dd',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_user_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'dt',
          'lb-col' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'dd',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_verdi_fields' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'dt',
          'fi' => TRUE,
          'fi-el' => 'dd',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_verdi_regions' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'dt',
          'lb-col' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'dd',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_user_quote' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'blockquote',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['user|user|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function pw_profiles_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'candidate_full_name';
  $ds_field->label = 'Full Name';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[user:field_user_fname] [user:field_user_lname]',
      'format' => 'php_code',
    ),
    'use_token' => 1,
  );
  $export['candidate_full_name'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'candidate_social_links';
  $ds_field->label = 'Social-Links';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<p><strong>Erfahren Sie mehr auf den sozialen Profilen des Kandierenden</strong></p>',
      'format' => 'php_code',
    ),
    'use_token' => 0,
  );
  $export['candidate_social_links'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'candidate_stats_questions_get';
  $ds_field->label = 'Candidate Stats';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<div class="candidate-detail-stats clearfix">
    <div class="pull-left candidate-detail-stats-count clearfix">
        <span class="value">[user:field_user_questions_get]</span>
        <span class="label">Fragen</span>
    </div>
    <div class="pull-left candidate-detail-stats-countasked">
        <div class="gauge-widget">
            <canvas class="gauge" width="60" height="60"></canvas>
            <div class="gauge-value" data-gauge-value="[user:field_user_answers_give]">[user:field_user_answers_give]%</div>
        </div>
        <span class="label">Beantwortet</span>
    </div>
</div>',
      'format' => 'php_code',
    ),
    'use_token' => 1,
  );
  $export['candidate_stats_questions_get'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'candidate_tab_navigation';
  $ds_field->label = 'Candidate Tab-Navigation';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<ul class="nav nav-tabs" role="tablist">
  <li role="presentation" class="active"><a href="#tab-questions-answers" aria-controls="questions-answers" role="tab" data-toggle="tab" aria-expanded="true">Fragen &amp; Antworten</a></li>
  <li role="presentation" class=""><a href="#tab-personal-description" aria-controls="personal-description" role="tab" data-toggle="tab" aria-expanded="false">Steckbrief</a></li>
</ul>
<a href="#" class="btn btn-primary btn-lg hidden-xs" data-toggle="modal" data-target="#modal_question" type="button">Jetzt Frage stellen</a>',
      'format' => 'php_code',
    ),
    'use_token' => 0,
  );
  $export['candidate_tab_navigation'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function pw_profiles_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|default';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_candidate_intro',
        1 => 'candidate_social_links',
        2 => 'candidate_full_name',
        3 => 'candidate_tab_navigation',
        4 => 'twitter',
        5 => 'group_user_name',
        6 => 'group_candidate_tabs',
        7 => 'group_candidate_tabs_wrapper',
        8 => 'group_candidate_intro_info',
        9 => 'field_user_twitter_account',
        10 => 'field_user_questions_get',
        11 => 'field_user_list',
        12 => 'field_user_quote',
        13 => 'field_user_picture',
        14 => 'candidate_stats_questions_get',
        15 => 'field_user_list_position',
        16 => 'field_user_picture_copyright',
        17 => 'group_candidate_tabs_questions',
        18 => 'field_user_title',
        19 => 'group_candidate_tabs_info_row',
        20 => 'field_user_fname',
        21 => 'group_candidate_tabs_info',
        22 => 'group_candidate_info_list',
        23 => 'field_user_lname',
        24 => 'field_user_birthday',
        25 => 'group_candidate_info_sidebar',
        26 => 'field_user_job_skills',
        27 => 'field_user_fraction',
        28 => 'field_verdi_fields',
        29 => 'field_verdi_regions',
        30 => 'field_user_commitee',
        31 => 'field_user_political_roles',
        32 => 'field_user_constituency',
        33 => 'field_user_first_letter_lname',
        34 => 'name',
        35 => 'group_candidate_intro_row',
        36 => 'group_candidate_intro_right',
        37 => 'group_candidate_intro_left',
      ),
    ),
    'fields' => array(
      'group_candidate_intro' => 'ds_content',
      'candidate_social_links' => 'ds_content',
      'candidate_full_name' => 'ds_content',
      'candidate_tab_navigation' => 'ds_content',
      'twitter' => 'ds_content',
      'group_user_name' => 'ds_content',
      'group_candidate_tabs' => 'ds_content',
      'group_candidate_tabs_wrapper' => 'ds_content',
      'group_candidate_intro_info' => 'ds_content',
      'field_user_twitter_account' => 'ds_content',
      'field_user_questions_get' => 'ds_content',
      'field_user_list' => 'ds_content',
      'field_user_quote' => 'ds_content',
      'field_user_picture' => 'ds_content',
      'candidate_stats_questions_get' => 'ds_content',
      'field_user_list_position' => 'ds_content',
      'field_user_picture_copyright' => 'ds_content',
      'group_candidate_tabs_questions' => 'ds_content',
      'field_user_title' => 'ds_content',
      'group_candidate_tabs_info_row' => 'ds_content',
      'field_user_fname' => 'ds_content',
      'group_candidate_tabs_info' => 'ds_content',
      'group_candidate_info_list' => 'ds_content',
      'field_user_lname' => 'ds_content',
      'field_user_birthday' => 'ds_content',
      'group_candidate_info_sidebar' => 'ds_content',
      'field_user_job_skills' => 'ds_content',
      'field_user_fraction' => 'ds_content',
      'field_verdi_fields' => 'ds_content',
      'field_verdi_regions' => 'ds_content',
      'field_user_commitee' => 'ds_content',
      'field_user_political_roles' => 'ds_content',
      'field_user_constituency' => 'ds_content',
      'field_user_first_letter_lname' => 'ds_content',
      'name' => 'ds_content',
      'group_candidate_intro_row' => 'ds_content',
      'group_candidate_intro_right' => 'ds_content',
      'group_candidate_intro_left' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['user|user|default'] = $ds_layout;

  return $export;
}
