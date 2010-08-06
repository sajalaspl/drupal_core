<?php
// $Id: template.php,v 1.1.1.1 2010/06/25 06:06:11 bhargav Exp $

/**
 * Sets the body-tag class attribute.
 *
 * Adds 'sidebar-left', 'sidebar-right' or 'sidebars' classes as needed.
 */
function phptemplate_body_class($left, $right) {
  if ($left != '' && $right != '') {
    $class = 'sidebars';
  }
  else {
    if ($left != '') {
      $class = 'sidebar-left';
    }
    if ($right != '') {
      $class = 'sidebar-right';
    }
  }

  if (isset($class)) {
    print ' class="'. $class .'"';
  }
}

/**
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *   An array containing the breadcrumb links.
 * @return a string containing the breadcrumb output.
 */
function phptemplate_breadcrumb($breadcrumb) {
  if (!empty($breadcrumb)) {
    return '<div class="breadcrumb">'. implode(' › ', $breadcrumb) .'</div>';
  }
}

/**
 * Override or insert PHPTemplate variables into the templates.
 */
function phptemplate_preprocess_page(&$vars) {
  $vars['tabs2'] = menu_secondary_local_tasks();

  // Hook into color.module
  if (module_exists('color')) {
    _color_page_alter($vars);
  }
}

/**
 * Add a "Comments" heading above comments except on forum pages.
 */
function garland_preprocess_comment_wrapper(&$vars) {
  if ($vars['content'] && $vars['node']->type != 'forum') {
    $vars['content'] = '<h2 class="comments">'. t('Comments') .'</h2>'.  $vars['content'];
  }
}

/**
 * Returns the rendered local tasks. The default implementation renders
 * them as tabs. Overridden to split the secondary tasks.
 *
 * @ingroup themeable
 */
function phptemplate_menu_local_tasks() {
  return menu_primary_local_tasks();
}

/**
 * Returns the themed submitted-by string for the comment.
 */
function phptemplate_comment_submitted($comment) {
  return t('!datetime — !username',
    array(
      '!username' => theme('username', $comment),
      '!datetime' => format_date($comment->timestamp)
    ));
}

/**
 * Returns the themed submitted-by string for the node.
 */
function phptemplate_node_submitted($node) {
  return t('!datetime — !username',
    array(
      '!username' => theme('username', $node),
      '!datetime' => format_date($node->created),
    ));
}

/**
 * Generates IE CSS links for LTR and RTL languages.
 */
function phptemplate_get_ie_styles() {
  global $language;

  $iecss = '<link type="text/css" rel="stylesheet" media="all" href="'. base_path() . path_to_theme() .'/fix-ie.css" />';
  if ($language->direction == LANGUAGE_RTL) {
    $iecss .= '<style type="text/css" media="all">@import "'. base_path() . path_to_theme() .'/fix-ie-rtl.css";</style>';
  }

  return $iecss;
}

function garland_preprocess_user_register(&$vars) {

/*  echo "<PRE>";
  		print_r($vars);
  echo "</PRE>";
  $vars['taTermsOfUse'] = drupal_render($vars['form']['terms_of_use']['terms_of_use']);
  $vars['taTermsOfUse1'] = drupal_render($vars['form']['terms_of_use']['terms_of_use1']);
  
  
  $vars['txtFirstName'] = drupal_render($vars['form']['Account information']['profile_firstname']);
  $vars['txtLastName'] = drupal_render($vars['form']['Account information']['profile_lastname']);
  $vars['txtUserName'] = drupal_render($vars['form']['account']['name']);
  $vars['txtUserEmail'] = drupal_render($vars['form']['account']['mail']);
  $vars['txtSecondaryEmail'] = drupal_render($vars['form']['Account information']['profile_secondaryemail']);
  $vars['taAddress'] = drupal_render($vars['form']['Account information']['profile_address']);
  $vars['txtZip'] = drupal_render($vars['form']['Account information']['profile_zip']);
  $vars['txtCity'] = drupal_render($vars['form']['Account information']['profile_city']);
  $vars['txtCountry'] = drupal_render($vars['form']['Account information']['profile_country']);
  $vars['txtPhone'] = drupal_render($vars['form']['Account information']['profile_phone']);
  $vars['txtBirthday'] = drupal_render($vars['form']['Account information']['profile_birthday']);
  $vars['txtGender'] = drupal_render($vars['form']['Account information']['profile_gender']);
  $vars['chkUsedInMarketing'] = drupal_render($vars['form']['Account information']['profile_usedinmarketing']);
  $vars['chkSendToInbox'] = drupal_render($vars['form']['Account information']['profile_sendtoinbox']);
  $vars['wdgtCaptcha'] = drupal_render($vars['form']['captcha']['captcha_widgets']);
  $vars['btnSubmit'] = drupal_render($vars['form']['submit']);
 */ 
	$block = module_invoke('block', 'block', 'view', 1);
	$vars['conformtaion_block'] = $block['content'];
	
  
}
function garland_theme(){
  return array(
    'user_register' => array(
      'arguments' => array('form' => NULL),
      // and if I use a template file, ie: user-register.tpl.php
      'template' => 'user-register',
    ),
  );
}
//function garland_user_register($form) {
  // Adding the fieldset
  /*$form['terms_of_use'] = array(
    '#type' => 'fieldset',
    '#title' => t('Terms of Use'),
    '#weight' => 4,
  );*/
  // Getting the node that contains the Terms of Use
  /*$node = node_load(402);
  $node = node_prepare($node);
  // Adding the Terms of Use to the fieldset
  $form['terms_of_use']['terms_of_use_text'] = array(
    '#prefix' => '<div class="content clear-block">',
    '#value' => $node->body,
    '#suffix' => '</div>',
  );
  // Adding the Terms of Use to the fieldset
  $form['terms_of_use']['I_agree'] = array(
    '#type' => 'checkbox',
    '#title' => t('I agree with these terms.'),
    '#required' => TRUE,
  );*/
  // dsm($form);   
  // returning the themed form
  //return drupal_render($form); 
//}




 