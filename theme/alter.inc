<?php
/**
 * @file
 * alter.inc
 *
 * Contains various implementations of hook_*_alter().
 */



/**
 * Implements hook_element_info_alter().
 */
function gumby_element_info_alter(&$elements) {
  foreach ($elements as &$element) {
    // Process all elements.
    $element['#process'][] = '_gumby_process_element';
    // Process input elements.
    if (!empty($element['#input'])) {
      $element['#process'][] = '_gumby_process_input';
    }

  }
}

/**
 * Implements hook_form_alter().
 */
function gumby_form_alter(array &$form, array &$form_state = array(), $form_id = NULL) {
  if ($form_id) {
    // IDs of forms that should be ignored. Make this configurable?
    // @todo is this still needed?
    $form_ids = array(
      'node_form',
      'system_site_information_settings',
      'user_profile_form',
      'node_delete_confirm',
    );
    // Only wrap in container for certain form.
    if (!in_array($form_id, $form_ids) && !isset($form['#node_edit_form']) && isset($form['actions']) && isset($form['actions']['#type']) && ($form['actions']['#type'] == 'actions')) {
      $form['actions']['#theme_wrappers'] = array();
    }

    switch ($form_id) {
      case 'system_theme_settings':
        // Include the settings form here.
        gumby_include('gumby', 'theme/settings.inc');
        _gumby_settings_form($form, $form_state);
        break;

      case 'search_form':
        // Add a clearfix class so the results don't overflow onto the form.
        $form['#attributes']['class'][] = 'clearfix';

        // Remove container-inline from the container classes.
        $form['basic']['#attributes']['class'] = array();

        // Hide the default button from display.
        $form['basic']['submit']['#attributes']['class'][] = 'element-invisible';

        // Implement a theme wrapper to add a submit button containing a search
        // icon directly after the input element.
        $form['basic']['keys']['#theme_wrappers'] = array('gumby_search_form_wrapper');
        $form['basic']['keys']['#title'] = '';
        //control the width of the input
        $form['basic']['#attributes']['class'][] ='wide';
        $form['basic']['keys']['#attributes']['placeholder'] = t('Search');
        break;

      case 'search_block_form':
        $form['#attributes']['class'][] = 'form-search';

        $form['search_block_form']['#title'] = '';
        $form['search_block_form']['#attributes']['placeholder'] = t('Search');
        //control the width of the input
		$form['search_block_form']['#attributes']['class'][] ='wide';
        // Hide the default button from display and implement a theme wrapper
        // to add a submit button containing a search icon directly after the
        // input element.
        $form['actions']['submit']['#attributes']['class'][] = 'element-invisible';
        $form['search_block_form']['#theme_wrappers'] = array('gumby_search_form_wrapper');

        // Apply a clearfix so the results don't overflow onto the form.
        $form['#attributes']['class'][] = 'content-search';
        break;
    }
  }
}


/**
 * Include #pre_render callbacks for elements.
 */
gumby_include('gumby', 'theme/pre-render.inc');

/**
 * Include #process callbacks for elements.
 */
gumby_include('gumby', 'theme/process.inc');
