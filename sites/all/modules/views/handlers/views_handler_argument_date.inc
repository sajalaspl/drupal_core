<?php
// $Id: views_handler_argument_date.inc,v 1.1 2010/06/29 07:05:36 sajal Exp $
/**
 * Abstract argument handler for dates.
 *
 * Adds an option to set a default argument based on the current date.
 *
 * @param $arg_format
 *   The format string to use on the current time when
 *   creating a default date argument.
 *
 * Definitions terms:
 * - many to one: If true, the "many to one" helper will be used.
 * - invalid input: A string to give to the user for obviously invalid input.
 *                  This is deprecated in favor of argument validators.
 * @see views_many_to_one_helper
 *
 * @ingroup views_argument_handlers
 */
class views_handler_argument_date extends views_handler_argument_formula {
  var $option_name = 'default_argument_date';
  var $arg_format = 'Y-m-d';

  /**
   * Add an option to set the default value to the current date.
   */
  function default_argument_form(&$form, &$form_state) {
    parent::default_argument_form($form, $form_state);
    $form['default_argument_type']['#options'] += array('date' => t('Current date'));
    $form['default_argument_type']['#options'] += array('node_created' => t("Current node's creation time"));
    $form['default_argument_type']['#options'] += array('node_changed' => t("Current node's update time"));  }

  /**
   * Set the empty argument value to the current date,
   * formatted appropriately for this argument.
   */
  function get_default_argument($raw = FALSE) {
    if (!$raw && $this->options['default_argument_type'] == 'date') {
      return date($this->arg_format, time());
    }
    else if (!$raw && in_array($this->options['default_argument_type'], array('node_created', 'node_changed'))) {
      foreach (range(1, 3) as $i) {
        $node = menu_get_object('node', $i);
        if (!empty($node)) {
          continue;
        }
      }
  
      if (arg(0) == 'node' && is_numeric(arg(1))) {
        $node = node_load(arg(1));
      }

      if (empty($node)) {
        return parent::get_default_argument();
      }
      else if ($this->options['default_argument_type'] == 'node_created') {
        return date($this->arg_format, $node->created);
      }
      else if ($this->options['default_argument_type'] == 'node_changed') {
        return date($this->arg_format, $node->changed);
      }
    }

    return parent::get_default_argument($raw);

  }
}
