<?php
// $Id: node.views.inc,v 1.1 2010/06/29 07:05:39 sajal Exp $
/**
 * @file
 * Provide views data and handlers for node.module
 */

/**
 * @defgroup views_node_module node.module handlers
 *
 * Includes the tables 'node', 'node_revisions' and 'history'.
 * @{
 */

/**
 * Implementation of hook_views_data()
 */
function node_views_data() {
  // ----------------------------------------------------------------
  // node table -- basic table information.

  // Define the base group of this table. Fields that don't
  // have a group defined will go into this field by default.
  $data['node']['table']['group']  = t('Node');

  // Advertise this table as a possible base table
  $data['node']['table']['base'] = array(
    'field' => 'nid',
    'title' => t('Node'),
    'help' => t("Nodes are a Drupal site's primary content."),
    'weight' => -10,
  );

  // For other base tables, explain how we join
  $data['node']['table']['join'] = array(
    // this explains how the 'node' table (named in the line above)
    // links toward the node_revisions table.
    'node_revisions' => array(
      'handler' => 'views_join', // this is actually optional
      'left_table' => 'node_revisions', // Because this is a direct link it could be left out.
      'left_field' => 'nid',
      'field' => 'nid',
      // also supported:
      // 'type' => 'INNER',
      // 'extra' => array(array('field' => 'fieldname', 'value' => 'value', 'operator' => '='))
      //   Unfortunately, you can't specify other tables here, but you can construct
      //   alternative joins in the handlers that can do that.
      // 'table' => 'the actual name of this table in the database',
     ),
  );

  // ----------------------------------------------------------------
  // node table -- fields

  // nid
  $data['node']['nid'] = array(
    'title' => t('Nid'),
    'help' => t('The node ID of the node.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_node_nid',
      'parent' => 'views_handler_argument_numeric', // make sure parent is included
      'name field' => 'title', // the field to display in the summary.
      'numeric' => TRUE,
      'validate type' => 'nid',
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // title
  // This definition has more items in it than it needs to as an example.
  $data['node']['title'] = array(
    'title' => t('Title'), // The item it appears as on the UI,
    'help' => t('The title of the node.'), // The help that appears on the UI,
     // Information for displaying a title as a field
    'field' => array(
      'field' => 'title', // the real field. This could be left out since it is the same.
      'group' => t('Node'), // The group it appears in on the UI. Could be left out.
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
     ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    // Information for accepting a title as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // created field
  $data['node']['created'] = array(
    'title' => t('Post date'), // The item it appears as on the UI,
    'help' => t('The date the node was posted.'), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // changed field
  $data['node']['changed'] = array(
    'title' => t('Updated date'), // The item it appears as on the UI,
    'help' => t('The date the node was last updated.'), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // Node type
  $data['node']['type'] = array(
    'title' => t('Type'), // The item it appears as on the UI,
    'help' => t('The type of a node (for example, "blog entry", "forum post", "story", etc).'), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_node_type',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_node_type',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_node_type',
    ),
  );

  // published status
  $data['node']['status'] = array(
    'title' => t('Published'),
    'help' => t('Whether or not the node is published.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Published'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // published status + extra
  $data['node']['status_extra'] = array(
    'title' => t('Published or admin'),
    'help' => t('Filters out unpublished nodes if the current user cannot view them.'),
    'filter' => array(
      'field' => 'status',
      'handler' => 'views_handler_filter_node_status',
      'label' => t('Published or admin'),
    ),
  );

  // promote status
  $data['node']['promote'] = array(
    'title' => t('Promoted to front page'),
    'help' => t('Whether or not the node is promoted to the front page.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Promoted to front page'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // moderate
  $data['node']['moderate'] = array(
    'title' => t('Moderated'), // The item it appears as on the UI,
    'help' => t('Whether or not the node is moderated.'), // The help that appears on the UI,
     // Information for displaying a title as a field
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Moderated'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // sticky
  $data['node']['sticky'] = array(
    'title' => t('Sticky'), // The item it appears as on the UI,
    'help' => t('Whether or not the node is sticky.'), // The help that appears on the UI,
     // Information for displaying a title as a field
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
      'output formats' => array(
        'sticky' => array('', t('Sticky')),
      ),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Sticky'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
      'help' => t('Whether or not the node is sticky. To list sticky nodes first, set this to descending.'),
    ),
  );

  // links to operate on the node

  $data['node']['view_node'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the node.'),
      'handler' => 'views_handler_field_node_link',
    ),
  );

  $data['node']['edit_node'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the node.'),
      'handler' => 'views_handler_field_node_link_edit',
    ),
  );

  $data['node']['delete_node'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the node.'),
      'handler' => 'views_handler_field_node_link_delete',
    ),
  );

  $data['node']['path'] = array(
    'field' => array(
      'title' => t('Path'),
      'help' => t('The aliased path to this node.'),
      'handler' => 'views_handler_field_node_path',
    ),
  );


  // Bogus fields for aliasing purposes.

  $data['node']['created_fulldate'] = array(
    'title' => t('Created date'),
    'help' => t('In the form of CCYYMMDD.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_fulldate',
    ),
  );

  $data['node']['created_year_month'] = array(
    'title' => t('Created year + month'),
    'help' => t('In the form of YYYYMM.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_year_month',
    ),
  );

  $data['node']['created_year'] = array(
    'title' => t('Created year'),
    'help' => t('In the form of YYYY.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_year',
    ),
  );

  $data['node']['created_month'] = array(
    'title' => t('Created month'),
    'help' => t('In the form of MM (01 - 12).'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_month',
    ),
  );

  $data['node']['created_day'] = array(
    'title' => t('Created day'),
    'help' => t('In the form of DD (01 - 31).'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_day',
    ),
  );

  $data['node']['created_week'] = array(
    'title' => t('Created week'),
    'help' => t('In the form of WW (01 - 53).'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_week',
    ),
  );

  $data['node']['changed_fulldate'] = array(
    'title' => t('Updated date'),
    'help' => t('In the form of CCYYMMDD.'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_created_fulldate',
    ),
  );

  $data['node']['changed_year_month'] = array(
    'title' => t('Updated year + month'),
    'help' => t('In the form of YYYYMM.'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_created_year_month',
    ),
  );

  $data['node']['changed_year'] = array(
    'title' => t('Updated year'),
    'help' => t('In the form of YYYY.'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_created_year',
    ),
  );

  $data['node']['changed_month'] = array(
    'title' => t('Updated month'),
    'help' => t('In the form of MM (01 - 12).'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_created_month',
    ),
  );

  $data['node']['changed_day'] = array(
    'title' => t('Updated day'),
    'help' => t('In the form of DD (01 - 31).'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_created_day',
    ),
  );

  $data['node']['changed_week'] = array(
    'title' => t('Updated week'),
    'help' => t('In the form of WW (01 - 53).'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_created_week',
    ),
  );

  // ----------------------------------------------------------------------
  // Node revisions table

  // Define the base group of this table. Fields that don't
  // have a group defined will go into this field by default.
  $data['node_revisions']['table']['group']  = t('Node revision');

  // Advertise this table as a possible base table
  $data['node_revisions']['table']['base'] = array(
    'field' => 'vid',
    'title' => t('Node revision'),
    'help' => t('Node revisions are a history of changes to nodes.'),
  );

  // For other base tables, explain how we join
  $data['node_revisions']['table']['join'] = array(
    // Directly links to node table.
    'node' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );

  // uid field
  $data['node_revisions']['uid'] = array(
    'title' => t('User'),
    'help' => t('Relate a node revision to the user who created the revision.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base field' => 'uid',
      'label' => t('user'),
    ),
  );

  // Body field
  $data['node_revisions']['body'] = array(
    'group' => t('Node'),
    'title' => t('Body'), // The item it appears as on the UI,
    'help' => t('The actual, full data in the body field; this may not be valid data on all node types.'), // The help that appears on the UI,
     // Information for displaying a title as a field
    'field' => array(
      'handler' => 'views_handler_field_markup',
      'format' => 'format', // The name of the format field
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  // Teaser field
  $data['node_revisions']['teaser'] = array(
    'group' => t('Node'),
    'title' => t('Teaser'), // The item it appears as on the UI,
    'help' => t('The stored teaser field. This may not be valid or useful data on all node types.'), // The help that appears on the UI,
     // Information for displaying a title as a field
    'field' => array(
      'handler' => 'views_handler_field_markup',
      'format' => 'format', // The name of the format field
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  // nid
  $data['node_revisions']['vid'] = array(
    'title' => t('Vid'),
    'help' => t('The revision ID of the node revision.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
//      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_node_vid',
      'parent' => 'views_handler_argument_numeric', // make sure parent is included
      'click sortable' => TRUE,
      'numeric' => TRUE,
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // title
  $data['node_revisions']['title'] = array(
    'title' => t('Title'), // The item it appears as on the UI,
    'help' => t('The title of the node.'), // The help that appears on the UI,
     // Information for displaying a title as a field
    'field' => array(
      'field' => 'title', // the real field
      'handler' => 'views_handler_field_node_revision',
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

  // log field
  $data['node_revisions']['log'] = array(
    'title' => t('Log message'), // The item it appears as on the UI,
    'help' => t('The log message entered when the revision was created.'), // The help that appears on the UI,
     // Information for displaying a title as a field
    'field' => array(
      'handler' => 'views_handler_field_xss',
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  // revision timestamp
  // changed field
  $data['node_revisions']['timestamp'] = array(
    'title' => t('Created date'), // The item it appears as on the UI,
    'help' => t('The date the node revision was created.'), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // input format id
  $data['node_revisions']['format'] = array(
    'title' => t('Input format id'), // The item it appears as on the UI,
    'help' => t('The numeric input format of the node revision. !default means the default input format.', array('!default' => FILTER_FORMAT_DEFAULT)), // The help that appears on the UI,
     // Information for displaying an input format as a field
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    // Information for sorting on input format
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    // Information for accepting input format as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  // input format name
  // A (numeric) format of 0 means the default; Drupal also applies the default
  // if the format specifed for a node revision has been deleted.
  // This complexity makes sorting and filtering by format name tricky,
  // hence these are not yet supported.
  $data['node_revisions']['format_name'] = array(
    'title' => t('Input format'), // The item it appears as on the UI,
    'help' => t('The name of the input format of the node revision.'), // The help that appears on the UI,
     // Information for displaying an input format as a field
    'field' => array(
      'handler' => 'views_handler_field_filter_format_name',
    ),
  );

  $data['node_revisions']['revert_revision'] = array(
    'field' => array(
      'title' => t('Revert link'),
      'help' => t('Provide a simple link to revert to the revision.'),
      'handler' => 'views_handler_field_node_revision_link_revert',
    ),
  );

  $data['node_revisions']['delete_revision'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the node revision.'),
      'handler' => 'views_handler_field_node_revision_link_delete',
    ),
  );

  // ----------------------------------------------------------------------
  // Node access table

  // Define the base group of this table. Fields that don't
  // have a group defined will go into this field by default.
  $data['node_access']['table']['group']  = t('Node access');

  // For other base tables, explain how we join
  $data['node_access']['table']['join'] = array(
    // Directly links to node table.
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );
  // nid field
  $data['node_access']['nid'] = array(
    'title' => t('Access'),
    'help' => t('Filter by access.'),
    'filter' => array(
      'handler' => 'views_handler_filter_node_access',
      'help' => t('Filter for nodes by view access. <strong>Not necessary if you are using node as your base table.</strong>'),
    ),
  );

  // ----------------------------------------------------------------------
  // History table

  // We're actually defining a specific instance of the table, so let's
  // alias it so that we can later add the real table for other purposes if we
  // need it.
  $data['history_user']['table']['group']  = t('Node');

  // Explain how this table joins to others.
  $data['history_user']['table']['join'] = array(
     // Directly links to node table.
    'node' => array(
      'table' => 'history',
      'left_field' => 'nid',
      'field' => 'nid',
      'extra' => array(
        array('field' => 'uid', 'value' => '***CURRENT_USER***', 'numeric' => TRUE),
      ),
    ),
  );

  $data['history_user']['timestamp'] = array(
    'title' => t('Has new content'),
    'field' => array(
      'handler' => 'views_handler_field_history_user_timestamp',
      'help' => t('Show a marker if the node has new or updated content.'),
    ),
    'filter' => array(
      'help' => t('Show only nodes that have new content.'),
      'handler' => 'views_handler_filter_history_user_timestamp',
    ),
  );
  return $data;
}

/**
 * Implementation of hook_views_handlers() to register all of the basic handlers
 * views uses.
 */
function node_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'views') . '/modules/node',
    ),
    'handlers' => array(
      // field handlers
      'views_handler_field_node' => array(
        'parent' => 'views_handler_field',
      ),
      'views_handler_field_node_type' => array(
        'parent' => 'views_handler_field_node',
      ),
      'views_handler_field_node_link' => array(
        'parent' => 'views_handler_field',
      ),
      'views_handler_field_node_path' => array(
        'parent' => 'views_handler_field',
      ),
      'views_handler_field_node_type' => array(
        'parent' => 'views_handler_field_node',
      ),
      'views_handler_field_node_link_edit' => array(
        'parent' => 'views_handler_field_node_link',
      ),
      'views_handler_field_node_link_delete' => array(
        'parent' => 'views_handler_field_node_link',
      ),
      'views_handler_field_node_revision_link_revert' => array(
        'parent' => 'views_handler_field_node_link',
      ),
      'views_handler_field_node_revision_link_delete' => array(
        'parent' => 'views_handler_field_node_link',
      ),
      'views_handler_field_history_user_timestamp' => array(
        'parent' => 'views_handler_field_node',
      ),
      'views_handler_field_node_revision' => array(
        'parent' => 'views_handler_field_node',
      ),
      // argument handlers
      'views_handler_argument_node_type' => array(
        'parent' => 'views_handler_argument',
      ),
      'views_handler_argument_node_nid' => array(
        'parent' => 'views_handler_argument_numeric',
      ),
      'views_handler_argument_node_vid' => array(
        'parent' => 'views_handler_argument_numeric',
      ),
      'views_handler_argument_node_created_fulldate' => array(
        // put several handlers in the same file
        'file' => 'views_handler_argument_dates_various.inc',
        'parent' => 'views_handler_argument_date',
      ),
      'views_handler_argument_node_created_year' => array(
        // put several handlers in the same file
        'file' => 'views_handler_argument_dates_various.inc',
        'parent' => 'views_handler_argument_date',
      ),
      'views_handler_argument_node_created_year_month' => array(
        // put several handlers in the same file
        'file' => 'views_handler_argument_dates_various.inc',
        'parent' => 'views_handler_argument_date',
      ),
      'views_handler_argument_node_created_month' => array(
        // put several handlers in the same file
        'file' => 'views_handler_argument_dates_various.inc',
        'parent' => 'views_handler_argument_date',
      ),
      'views_handler_argument_node_created_day' => array(
        // put several handlers in the same file
        'file' => 'views_handler_argument_dates_various.inc',
        'parent' => 'views_handler_argument_date',
      ),
      'views_handler_argument_node_created_week' => array(
        // put several handlers in the same file
        'file' => 'views_handler_argument_dates_various.inc',
        'parent' => 'views_handler_argument_date',
      ),

      // filters
      'views_handler_filter_node_type' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'views_handler_filter_history_user_timestamp' => array(
        'parent' => 'views_handler_filter',
      ),
      'views_handler_filter_node_status' => array(
        'parent' => 'views_handler_filter',
      ),
      'views_handler_filter_node_access' => array(
        'parent' => 'views_handler_filter',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_plugins
 */
function node_views_plugins() {
  return array(
    'module' => 'views', // This just tells our themes are elsewhere.
    'row' => array(
      'node' => array(
        'title' => t('Node'),
        'help' => t('Display the node with standard node view.'),
        'handler' => 'views_plugin_row_node_view',
        'path' => drupal_get_path('module', 'views') . '/modules/node', // not necessary for most modules
        'theme' => 'views_view_row_node',
        'base' => array('node'), // only works with 'node' as base.
        'uses options' => TRUE,
        'type' => 'normal',
        'help topic' => 'style-node',
      ),
      'node_rss' => array(
        'title' => t('Node'),
        'help' => t('Display the node with standard node view.'),
        'handler' => 'views_plugin_row_node_rss',
        'path' => drupal_get_path('module', 'views') . '/modules/node', // not necessary for most modules
        'theme' => 'views_view_row_rss',
        'base' => array('node'), // only works with 'node' as base.
        'uses options' => TRUE,
        'type' => 'feed',
        'help topic' => 'style-node-rss',
      ),
    ),
    'argument validator' => array(
      'node' => array(
        'title' => t('Node'),
        'handler' => 'views_plugin_argument_validate_node',
        'path' => drupal_get_path('module', 'views') . '/modules/node', // not necessary for most modules
      ),
    ),
    'argument default' => array(
      'node' => array(
        'title' => t('Node ID from URL'),
        'handler' => 'views_plugin_argument_default_node',
        'path' => drupal_get_path('module', 'views') . '/modules/node', // not necessary for most modules
        'parent' => 'fixed', // so that the parent class is included
      ),
    ),
  );
}

/**
 * Template helper for theme_views_view_row_node
 */
function template_preprocess_views_view_row_node(&$vars) {
  $options = $vars['options'];

  // Make sure the variables are defined.
  $vars['node'] = '';
  $vars['comments'] = '';

  $nid = $vars['row']->{$vars['field_alias']};
  if (!is_numeric($nid)) {
    return;
  }

  $node = node_load($nid);

  if (empty($node)) {
    return;
  }

  $node->view = $vars['view'];
  $node->build_mode = ($options['build_mode'] == 'teaser' || $options['build_mode'] == 'full') ? NODE_BUILD_NORMAL : $options['build_mode'];
  $vars['node'] = node_view($node, $options['build_mode'] == 'teaser', FALSE, $options['links']);

  if (!empty($options['comments']) && function_exists('comment_render')) {
    $vars['comments'] = comment_render($node);
  }
}

/**
 * Implementation of hook_views_query_substitutions().
 */
function node_views_query_substitutions() {
  return array(
    '***ADMINISTER_NODES***' => intval(user_access('administer nodes')),
  );
}

/**
 * Implementation of hook_views_analyze().
 */
function node_views_analyze($view) {
  $ret = array();
  // Check for something other than the default display:
  if ($view->base_table == 'node') {
    foreach ($view->display as $id => $display) {
      if (!$display->handler->is_defaulted('access') || !$display->handler->is_defaulted('filters')) {
        // check for no access control
        $access = $display->handler->get_option('access');
        if (empty($access['type']) || $access['type'] == 'none') {
          $filters = $display->handler->get_option('filters');
          foreach ($filters as $filter) {
            if ($filter['table'] == 'node' && ($filter['field'] == 'status' || $filter['field'] == 'status_extra')) {
              continue 2;
            }
          }
          $ret[] = views_ui_analysis(t('Display %display has no access control but does not contain a filter for published nodes.', array('%display' => $display->display_title)), 'warning');
        }
      }
    }
  }
  foreach ($view->display as $id => $display) {
    if ($display->display_plugin == 'page') {
      if ($display->handler->get_option('path') == 'node/%') {
        $ret[] = views_ui_analysis(t('Display %display has set node/% as path. This will not produce what you want. If you want to have multiple versions of the node view, use panels.', array('%display' => $display->display_title)), 'warning');
      }
    }
  }

  return $ret;
}

/**
 * @}
 */
