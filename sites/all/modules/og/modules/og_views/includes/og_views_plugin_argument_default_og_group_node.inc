<?php
// $Id: og_views_plugin_argument_default_og_group_node.inc,v 1.1 2010/06/29 07:05:33 sajal Exp $
/**
 * @file
 * Contains the group node argument default plugin.
 */

/**
 * Default argument plugin to extract the current group node.
 */
class og_views_plugin_argument_default_og_group_node extends views_plugin_argument_default {
  function argument_form(&$form, &$form_state) {
  }

  function get_argument() {
    if ($group_node = og_get_group_context()) {
      return $group_node->nid;
    }
  }
}
