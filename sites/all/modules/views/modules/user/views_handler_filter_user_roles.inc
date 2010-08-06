<?php
// $Id: views_handler_filter_user_roles.inc,v 1.1 2010/06/29 07:05:43 sajal Exp $
/**
 * Filter handler for user roles
 */
class views_handler_filter_user_roles extends views_handler_filter_many_to_one {
  function get_value_options() {
    $this->value_options = user_roles(TRUE);
    unset($this->value_options[DRUPAL_AUTHENTICATED_RID]);
  }
}
