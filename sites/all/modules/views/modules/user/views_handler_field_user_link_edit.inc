<?php
// $Id: views_handler_field_user_link_edit.inc,v 1.1 2010/06/29 07:05:42 sajal Exp $
/**
 * Field handler to present a link to user edit.
 */
class views_handler_field_user_link_edit extends views_handler_field_user_link {
  function render($values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $uid = $values->{$this->aliases['uid']};
    // Fake object to check access.
    $account = new stdClass();
    $account->uid = $uid;
    if (user_edit_access($account)) {
      return l($text, "user/$uid/edit", array('query' => drupal_get_destination()));
    }
  }
}

