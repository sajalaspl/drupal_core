<?php
// $Id: views_handler_field_comment_depth.inc,v 1.1 2010/06/29 07:05:39 sajal Exp $
/**
 * Field handler to display the depth of a comment
 */
class views_handler_field_comment_depth extends views_handler_field {
  /**
   * Work out the depth of this comment
   */
  function render($values) {
    return count(explode('.', $values->comments_thread)) - 1;
  }
}

