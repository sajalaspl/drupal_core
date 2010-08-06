<?php
// $Id: views_handler_field_file_status.inc,v 1.1 2010/06/29 07:05:42 sajal Exp $
/**
 * Field handler to translate a node type into its readable form.
 */
class views_handler_field_file_status extends views_handler_field {
  function render($values) {
    return _views_file_status($values->{$this->field_alias});
  }
}

