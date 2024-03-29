<?php
// $Id: views_handler_argument_formula.inc,v 1.1 2010/06/29 07:05:36 sajal Exp $
/**
 * Abstract argument handler for simple formulae.
 *
 * Child classes of this object should implement summary_argument, at least.
 *
 * Definition terms:
 * - formula: The formula to use for this handler.
 *
 * @ingroup views_argument_handlers
 */
class views_handler_argument_formula extends views_handler_argument {
  var $formula = NULL;
  /**
   * Constructor
   */
  function construct() {
    parent::construct();

    if (!empty($this->definition['formula'])) {
      $this->formula = $this->definition['formula'];
    }
  }

  function get_formula() {
    return str_replace('***table***', $this->table_alias, $this->formula);
  }

  /**
   * Build the summary query based on a formula
   */
  function summary_query() {
    $this->ensure_my_table();
    // Now that our table is secure, get our formula.
    $formula = $this->get_formula();

    // Add the field.
    $this->base_alias = $this->name_alias = $this->query->add_field(NULL, $formula, $this->field);
    $this->query->set_count_field(NULL, $formula, $this->field);

    return $this->summary_basics(FALSE);
  }

  /**
   * Build the query based upon the formula
   */
  function query() {
    $this->ensure_my_table();
    // Now that our table is secure, get our formula.
    $formula = $this->get_formula();

    $this->query->add_where(0, "$formula = '%s'", $this->argument);
  }
}
