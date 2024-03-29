<?php
// $Id: poll.views.inc,v 1.1 2010/06/29 07:05:39 sajal Exp $
/**
 * @file
 * Provide views data and handlers for poll.module
 */

/**
 * @defgroup views_poll_module poll.module handlers
 *
 * Includes only the core 'poll' table for now.
 * @{
 */

/**
 * Implementation of hook_views_data()
 */
function poll_views_data() {
  // Basic table information.
  $data['poll']['table']['group']  = t('Poll');

  // Join to 'node' as a base table.
  $data['poll']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  // ----------------------------------------------------------------
  // Fields

  // poll active status
  $data['poll']['active'] = array(
    'title' => t('Active'),
    'help' => t('Whether the poll is open for voting.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Active'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}

/**
 * @}
 */
