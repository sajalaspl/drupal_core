<?php
// $Id: views_handler_field_locale_language.inc,v 1.1 2010/06/29 07:05:41 sajal Exp $

/**
 * Field handler to translate a language into its readable form.
 */
class views_handler_field_locale_language extends views_handler_field {
  function render($values) {
    $languages = language_list();
    return isset($languages[$values->{$this->field_alias}]) ? $languages[$values->{$this->field_alias}]->name : '';
  }
}
