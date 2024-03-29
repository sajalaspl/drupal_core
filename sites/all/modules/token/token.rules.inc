<?php
// $Id: token.rules.inc,v 1.1 2010/06/29 07:05:35 sajal Exp $
/**
 * @file
 * Rules integration for the token module.
 *
 * This provides a token input evaluator, so that token replacements can be used
 * in every rules action.
 */

/**
 * Implementation of hook_rules_evaluator().
 */
function token_rules_evaluator() {
  return array(
    'token_rules_input_evaluator' => array(
      'label' => t('Token replacement patterns'),
      'weight' => -5,
    ),
  );
}

/**
 * Prepares the evalution.
 *
 * @param $string
 *   The string to evaluate later.
 * @param $variables
 *   An array of available variables.
 * @return
 *   Arbitrary data, which is passed to the evaluator on evaluation.
 *   If NULL is returned the input evaluator will be skipped later.
 */
function token_rules_input_evaluator_prepare($string, $variables) {
  $used_vars = array();
  foreach ($variables as $name => $info) {
    if (strpos($string, '['. $name .':') !== FALSE) {
      $used_vars[] = $name;
    }
  }
  return $used_vars ? $used_vars : NULL;
}

/**
 * Apply the input evaluator.
 *
 * @param $text
 *   The string for which tokens should be replaced.
 * @param $used_vars
 *   The used variables as returned from preparation.
 * @param $state
 *   The current evaluation state of rules.
 */
function token_rules_input_evaluator_apply($text, $used_vars, &$state) {
  static $token_cache = array();

  if ($used_vars) {
    $vars = rules_get_variables(drupal_map_assoc($used_vars), $state);
    if (!$vars) {
      //there not all needed variables available!
      return FALSE;
    }

    foreach ($used_vars as $name) {
      $type = _token_rules_map_type($state['variables'][$name]->info['type']);
      if ($type) {
        $token_id = _token_get_id($type, $vars[$name]);
        if (isset($token_cache[$token_id]) && $token_cache[$token_id] != $name) {
          // this is the same variable in another state
          // so we need to flush the token cache to get the fresh values
          token_get_values('global', NULL, TRUE);
        }

        $text = token_replace($text, $type, $vars[$name], '['. $name .':', ']');

        // remember that this variable has been used and got cached
        $token_cache[$token_id] = $name;
      }
    }
  }

  return $text;
}

/**
 * Map rules types to corresponding token types
 */
function _token_rules_map_type($type) {
  if (($data_type = rules_get_data_types($type)) && isset($data_type['token type'])) {
    return $data_type['token type'];
  }
  return $type;
}

/**
 * Some token replacement help for the condition/action edit form.
 */
function token_rules_input_evaluator_help($variables) {

  foreach ($variables as $name => $info) {
    $type = _token_rules_map_type($info['type']);
    if ($type) {
      $form[$name] = array(
        '#type' => 'fieldset',
        '#title' => t('Replacement patterns for @name', array('@name' => $info['label'])),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $form[$name]['content'] = array(
        '#value' => theme('token_help', $type, '['. $name . ':', ']'),
      );
    }
  }
  return $form;
}
