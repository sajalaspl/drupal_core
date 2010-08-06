<?php
// $Id: views_handler_field_comment_link_edit.inc,v 1.1 2010/06/29 07:05:39 sajal Exp $
/**
 * Field handler to present a link node edit.
 */
class views_handler_field_comment_link_edit extends views_handler_field_comment_link {
  function construct() {
    parent::construct();
    $this->additional_fields['uid'] = 'uid';
  }

  function render($values) {
    // ensure user has access to edit this comment.
    $comment = new stdClass();
    $comment->cid = $values->{$this->aliases['cid']};
    $comment->uid = $values->{$this->aliases['uid']};
    if (!comment_access('edit', $comment)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    return l($text, "comment/edit/" . $values->{$this->aliases['cid']});
  }
}

