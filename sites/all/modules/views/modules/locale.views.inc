<?php
// $Id: locale.views.inc,v 1.1 2010/06/29 07:05:39 sajal Exp $

/**
 * @file
 *
 * Provides views data and handlers for locale.module.
 */

/**
 * @defgroup views_locale_module locale.module handlers
 *
 * @{
 */

/**
 * Implementation of hook_views_data().
 */
function locale_views_data() {
  // Basic table information.

  // Define the base group of this table.
  $data['locales_source']['table']['group']  = t('Locale source');

  // Advertise this table as a possible base table.
  $data['locales_source']['table']['base'] = array(
    'field' => 'lid',
    'title' => t('Locale source'),
    'help' => t('A source string for translation, in English or the default site language.'),
  );

  // lid
  $data['locales_source']['lid'] = array(
    'title' => t('LID'),
    'help' => t('The ID of the source string.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
      'validate type' => 'lid',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // location
  $data['locales_source']['location'] = array(
    'group' => t('Locale source'),
    'title' => t('Location'),
    'help' => t('A description of the location or context of the string.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Group field
  $data['locales_source']['textgroup'] = array(
    'group' => t('Locale source'),
    'title' => t('Group'),
    'help' => t('The group the translation is in.'),
    'field' => array(
      'handler' => 'views_handler_field_locale_group',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_locale_group',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_locale_group',
    ),
  );

  // Source field
  $data['locales_source']['source'] = array(
    'group' => t('Locale source'),
    'title' => t('Source'),
    'help' => t('The full original string.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  // Version field
  $data['locales_source']['version'] = array(
    'group' => t('Locale source'),
    'title' => t('Version'),
    'help' => t('The version of Drupal core that this string is for.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_locale_version',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['locales_source']['edit_lid'] = array(
    'group' => t('Locale source'),
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the translations.'),
      'handler' => 'views_handler_field_locale_link_edit',
    ),
  );

  // ----------------------------------------------------------------------
  // Locales target table

  // Define the base group of this table. Fields that don't
  // have a group defined will go into this field by default.
  $data['locales_target']['table']['group']  = t('Locale target');

  // Join information
  $data['locales_target']['table']['join'] = array(
    'locales_source' => array(
      'left_field' => 'lid',
      'field' => 'lid',
    ),
  );

  // Translation field
  $data['locales_target']['translation'] = array(
    'group' => t('Locale target'),
    'title' => t('Translation'),
    'help' => t('The full translation string.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  // Language field
  $data['locales_target']['language'] = array(
    'group' => t('Locale target'),
    'title' => t('Language'),
    'help' => t('The language this translation is in.'),
    'field' => array(
      'handler' => 'views_handler_field_locale_language',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_locale_language',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_locale_language',
    ),
  );

  $data['locales_target']['plid'] = array(
    'group' => t('Locale target'),
    'title' => t('Singular LID'),
    'help' => t('The ID of the parent translation.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
  );

  // Plural
  $data['locales_target']['plural'] = array(
    'group' => t('Locale target'),
    'title' => t('Plural'),
    'help' => t('Whether or not the translation is plural.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Plural'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function locale_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'views') . '/modules/locale',
    ),
    'handlers' => array(
      // Field handlers.
      'views_handler_field_locale_group' => array(
        'parent' => 'views_handler_field',
      ),
      'views_handler_field_locale_language' => array(
        'parent' => 'views_handler_field',
      ),
      'views_handler_field_locale_link_edit' => array(
        'parent' => 'views_handler_field',
      ),
      // Argument handlers.
      'views_handler_argument_locale_group' => array(
        'parent' => 'views_handler_argument',
      ),
      'views_handler_argument_locale_language' => array(
        'parent' => 'views_handler_argument',
      ),
      // Filters.
      'views_handler_filter_locale_group' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'views_handler_filter_locale_language' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'views_handler_filter_locale_version' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
    ),
  );
}

/**
 * @}
 */
