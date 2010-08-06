<?php
// $Id: views_handler_field_node_language.inc,v 1.1 2010/06/29 07:05:42 sajal Exp $

/**
 * Field handler to translate a language into its readable form.
 */
class views_handler_field_node_language extends views_handler_field_node {
  function render($values) {
    $languages = locale_language_list();
    $value = isset($languages[$values->{$this->field_alias}]) ? $languages[$values->{$this->field_alias}] : '';
    return $this->render_link($value, $values);
  }
}
