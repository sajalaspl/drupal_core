<?php
// $Id: views_plugin_style_grid.inc,v 1.1 2010/06/29 07:05:43 sajal Exp $
/**
 * @file
 * Contains the grid style plugin.
 */

/**
 * Style plugin to render each item in a grid cell.
 *
 * @ingroup views_style_plugins
 */
class views_plugin_style_grid extends views_plugin_style {
  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['columns'] = array('default' => '4');
    $options['alignment'] = array('default' => 'horizontal');
    $options['fill_single_line'] = array('default' => TRUE);

    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['columns'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of columns'),
      '#default_value' => $this->options['columns'],
    );
    $form['alignment'] = array(
      '#type' => 'radios',
      '#title' => t('Alignment'),
      '#options' => array('horizontal' => t('Horizontal'), 'vertical' => t('Vertical')),
      '#default_value' => $this->options['alignment'],
      '#description' => t('Horizontal alignment will place items starting in the upper left and moving right. Vertical alignment will place items starting in the upper left and moving down.'),
    );
    
    $form['fill_single_line'] = array(
      '#type' => 'checkbox',
      '#title' => t('Fill up single line'),
      '#description' => t('If you disable this option a grid with only one row will have the amount of items as tds. If you disable it this can cause problems with your css.'),
      '#default_value' => !empty($this->options['fill_single_line']),
    );
  }
}

