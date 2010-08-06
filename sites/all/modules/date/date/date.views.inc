<?php
//$Id: date.views.inc,v 1.1.1.1 2010/07/16 06:17:00 bhargav Exp $

/**
 * Implementation of hook_views_handlers().
 */
function date_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'date'),
    ),
    // A date-specific handler for grouping multiple values.
    'handlers' => array(
      'date_handler_field_multiple' => array(
        'parent' => 'content_handler_field_multiple',
      ),
     ),
   );
}
