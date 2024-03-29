<?php
// $Id: views_handler_field_comment_link_delete.inc,v 1.1 2010/06/29 07:05:39 sajal Exp $
/**
 * Field handler to present a link to delete a node.
 */
class views_handler_field_comment_link_delete extends views_handler_field_comment_link {
  function render($values) {
    //needs permission to administer comments in general
    if (!user_access('administer comments')) {
      return;
    }
    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    return l($text, "comment/delete/" . $values->{$this->aliases['cid']}, array('query' => drupal_get_destination()));
  }
}
