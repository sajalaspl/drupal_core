<?php
// $Id: views_plugin_cache_none.inc,v 1.1 2010/06/29 07:05:43 sajal Exp $

/**
 * Caching plugin that provides no caching at all.
 */
class views_plugin_cache_none extends views_plugin_cache {
  function cache_start() { /* do nothing */ }

  function summary_title() {
    return t('None');
  }

  function cache_get($type) {
    return FALSE;
  }

  function cache_set($type) { }
}
