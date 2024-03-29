<?php
// $Id: views_handler_argument_taxonomy.inc,v 1.1 2010/06/29 07:05:42 sajal Exp $

/**
 * Argument handler for basic taxonomy tid.
 */
class views_handler_argument_taxonomy extends views_handler_argument {

  /**
   * Override the behavior of title(). Get the title of the node.
   */
  function title() {
    $term = taxonomy_get_term($this->argument);
    if (!empty($term)) {
      return check_plain($term->name);
    }
    // TODO review text
    return t('No name');
  }
}
