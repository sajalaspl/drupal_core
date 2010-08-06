<?php
// $Id: views_handler_filter_node_language.inc,v 1.1 2010/06/29 07:05:42 sajal Exp $
/**
 * Filter by language
 */
class views_handler_filter_node_language extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Language');
      $languages = array('***CURRENT_LANGUAGE***' => t("Current user's language"), '***DEFAULT_LANGUAGE***' => t("Default site language"), '***NO_LANGUAGE***' => t('No language'));
      $languages = array_merge($languages, locale_language_list());
      $this->value_options = $languages;
    }
  }
}

