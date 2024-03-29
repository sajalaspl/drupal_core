<?php
// $Id: filefield.views.inc,v 1.1 2010/06/29 07:05:30 sajal Exp $
/**
 * @file
 * Provide views data for filefield.module.
 */

/**
 * @defgroup views_filefield_module filefield.module handlers
 *
 * Includes the handler for the FileField data column.
 * @{
 */

/**
 * Implementation of hook_views_handlers().
 */
function filefield_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'filefield') . '/views',
    ),
    'handlers' => array(
      // field handlers
      'filefield_handler_field_data' => array(
        'parent' => 'views_handler_field_node',
      ),
    ),
  );
}

/**
 * @}
 */
