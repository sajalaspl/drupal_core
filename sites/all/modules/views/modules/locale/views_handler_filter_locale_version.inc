<?php
// $Id: views_handler_filter_locale_version.inc,v 1.1 2010/06/29 07:05:42 sajal Exp $

/**
 * Filter by version.
 */
class views_handler_filter_locale_version extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Version');
      // Enable filtering by the current installed Drupal version.
      $versions = array('***CURRENT_VERSION***' => t('Current installed version'));
      $result = db_query('SELECT DISTINCT(version) FROM {locales_source} ORDER BY  version');
      while ($row = db_fetch_array($result)) {
        if (!empty($row['version'])) {
          $versions[$row['version']] = $row['version'];
        }
      }
      $this->value_options = $versions;
    }
  }
}
