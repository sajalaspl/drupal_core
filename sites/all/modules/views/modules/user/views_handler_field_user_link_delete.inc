<?php
// $Id: views_handler_field_user_link_delete.inc,v 1.1 2010/06/29 07:05:42 sajal Exp $
/**
 * Field handler to present a link to user delete.
 */
class views_handler_field_user_link_delete extends views_handler_field_user_link {
  // An example of field level access control.
  function access() {
    return user_access('administer users');
  }

  function render($values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    $uid = $values->{$this->aliases['uid']};
    return l($text, "user/$uid/delete", array('query' => drupal_get_destination()));
  }
}

