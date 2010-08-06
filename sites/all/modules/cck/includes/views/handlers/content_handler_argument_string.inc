<?php
// $Id: content_handler_argument_string.inc,v 1.1 2010/06/29 07:05:25 sajal Exp $

/**
 * @file
 * The subclass simply adds properties,
 * for field-specific subclasses to use if they need to.
 */
class content_handler_argument_string extends views_handler_argument_string {
  var $content_field;

  function construct() {
    parent::construct();

    $this->content_field = content_fields($this->definition['content_field_name']);
    $this->additional_fields = $this->definition['additional fields'];
  }
}