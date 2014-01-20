<?php

/**
 * Implements hook_form_alter().
 */
function gumby_form_alter(&$form, &$form_state, $form_id) {
  // Id's of forms that should be ignored
  // Make this configurable?
  $form_ids = array(
    'node_form',
    'system_site_information_settings',
    'user_profile_form',
    'node_delete_confirm',
  );

  // Only wrap in container for certain form
  if (isset($form['#form_id']) && !in_array($form['#form_id'], $form_ids) && !isset($form['#node_edit_form']) && isset($form['actions']) && ($form['actions']['#type'] == 'actions')) {
    $form['actions']['#theme_wrappers'] = array();
  }
}

/**
 * Implements hook_form_FORM_ID_alter() for search_form().
 */
function gumby_form_search_form_alter(&$form, &$form_state) {
  $form['#attributes']['class'][] = 'form-search';
  $form['#attributes']['class'][] = 'pull-left';

  $form['basic']['keys']['#title'] = '';
  $form['basic']['keys']['#attributes']['class'][] = 'search-query';
  $form['basic']['keys']['#attributes']['class'][] = 'span2';
  $form['basic']['keys']['#attributes']['placeholder'] = t('Search');

  // Hide the default button from display and implement a theme wrapper to add
  // a submit button containing a search icon directly after the input element.
  $form['basic']['submit']['#attributes']['class'][] = 'element-invisible';
  $form['basic']['keys']['#theme_wrappers'][] = 'gumby_search_form_wrapper';

  // Apply a clearfix so the results don't overflow onto the form.
  $form['#suffix'] = '<div class="clearfix"></div>';
  $form['#attributes']['class'][] = 'content-search';
}

/**
 * Implements hook_form_FORM_ID_alter() for search_block_form().
 */
function gumby_form_search_block_form_alter(&$form, &$form_state) {
  $form['#attributes']['class'][] = 'form-search';

  $form['search_block_form']['#title'] = '';
  $form['search_block_form']['#attributes']['class'][] = 'search-query';
  $form['search_block_form']['#attributes']['class'][] = 'span2';
  $form['search_block_form']['#attributes']['placeholder'] = t('Search');

  // Hide the default button from display and implement a theme wrapper to add
  // a submit button containing a search icon directly after the input element.
  $form['actions']['submit']['#attributes']['class'][] = 'element-invisible';
  $form['search_block_form']['#theme_wrappers'][] = 'gumby_search_form_wrapper';

  // Apply a clearfix so the results don't overflow onto the form.
  $form['#attributes']['class'][] = 'content-search';
}

/**
 * Returns HTML for a form element.
 */
function gumby_form_element(&$variables) {
  $element = &$variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }

  $exclude_control = FALSE;
  $control_wrapper = '<div class="field">';
  // Add gumby class
  if (isset($element['#type']) && ($element['#type'] == "radio" || $element['#type'] == "checkbox")){
    $exclude_control = TRUE;
  }
  else {
    $attributes['class'] = array('control-group');
  }

  // Check for errors and set correct error class
  if (isset($element['#parents']) && form_get_error($element)) {
    $attributes['class'][] = 'error';
  }

  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  $attributes['class'][] = 'form-item';
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  // Prepare input whitelist - added to ensure ajax functions don't break
  $whitelist = _gumby_element_whitelist();

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      // Check if item exists in element whitelist
      if (isset($element['#id']) && in_array($element['#id'], $whitelist)) {
        $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
        $exclude_control = TRUE;
      }
      else {
        $output = $exclude_control ? $output : $output.$control_wrapper;
        $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      }
      break;

    case 'after':
      $output = $exclude_control ? $output : $output.$control_wrapper;
      $variables['#children'] = ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output = $exclude_control ? $output : $output.$control_wrapper;
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if ( !empty($element['#description']) ) {
    $output .= '<p class="help-block">' . $element['#description'] . "</p>\n";
  }

  // Check if control wrapper was added to ensure we close div correctly
  if ($exclude_control) {
    $output .= "</div>\n";
  }
  else {
    $output .= "</div></div>\n";
  }
  return $output;
}
/**
 * Replacement for theme_webform_element().
 */
function gumby_webform_element($variables) {
  // Ensure defaults.
  $variables['element'] += array(
    '#title_display' => 'before',
  );

  $element = $variables['element'];

  // All elements using this for display only are given the "display" type.
  if (isset($element['#format']) && $element['#format'] == 'html') {
    $type = 'display';
  }
  else {
    $type = (isset($element['#type']) && !in_array($element['#type'], array('markup', 'textfield', 'webform_email', 'webform_number'))) ? $element['#type'] : $element['#webform_component']['type'];
  }

  // Convert the parents array into a string, excluding the "submitted" wrapper.
  $nested_level = $element['#parents'][0] == 'submitted' ? 1 : 0;
  $parents = str_replace('_', '-', implode('--', array_slice($element['#parents'], $nested_level)));

  $wrapper_classes = array(
		'field',
   'form-item',
   'webform-component',
   'webform-component-' . $type,
  );
  if (isset($element['#title_display']) && strcmp($element['#title_display'], 'inline') === 0) {
    $wrapper_classes[] = 'webform-container-inline';
  }
  $output = '<div class="' . implode(' ', $wrapper_classes) . '" id="webform-component-' . $parents . '">' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . _webform_filter_xss($element['#field_prefix']) . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . _webform_filter_xss($element['#field_suffix']) . '</span>' : '';

  switch ($element['#title_display']) {
    case 'inline':
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= ' <div class="description">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}



/**
 * Returns HTML for a form element label and required marker.
 */
function gumby_form_element_label(&$variables) {
  $element = $variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // If title and required marker are both empty, output no label.
  if ((!isset($element['#title']) || $element['#title'] === '' && $element['#type'] !== 'radio' && $element['#type'] !== 'checkbox') && empty($element['#required'])) {
    return '';
  }

  // If the element is required, a required marker is appended to the label.
  $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';

  $title = filter_xss_admin($element['#title']);

  $attributes = array();
  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $attributes['class'][] = 'option';
    $attributes['class'][] = $element['#type'];
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'][] = 'element-invisible';
  }

  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }

  // @gumby: Add gumby control-label class except for radio.
  if ($element['#type'] != 'radio') {
    $attributes['class'][] = 'control-label';
  }
  // @gumby: Insert radio and checkboxes inside label elements.
  $output = '';
  if ( isset($variables['#children']) ) {
    $output .= $variables['#children'];
  }

  // @gumby: Append label
  $output .= $t('!title !required', array('!title' => $title, '!required' => $required));

  // The leading whitespace helps visually separate fields from inline labels.
  return ' <label' . drupal_attributes($attributes) . '>' . $output . "</label>\n";
}

/**
 * Preprocessor for theme('button').
 */
function gumby_preprocess_button(&$vars) {
  $vars['element']['#attributes']['class'][] = 'btn pretty rounded medium';

  if (isset($vars['element']['#value'])) {
    $classes = array(
      //specifics
      t('Save and add') => 'info',
      t('Add another item') => 'info',
      t('Add effect') => 'primary',
      t('Add and configure') => 'primary',
      t('Update style') => 'primary',
      t('Download feature') => 'primary',
      t('Save configuration') => 'primary',
      t('E-mail new password') => 'primary',      
      t('Clear all caches') => 'primary',
      t('Enable and save') => 'primary',
      t('Disable and save') => 'warning',
      t('Download these updates') => 'warning',      
      t('Re-index site') => 'primary',
      
      //generals
      t('Save') => 'primary',
      t('Enable') => 'primary',
      t('Disable') => 'warning',
      t('Apply') => 'primary',
      t('Publish') => 'primary',
      t('Log in') => 'primary',
      t('Create') => 'primary',
      t('Confirm') => 'primary',
      t('Submit') => 'primary',
      t('Export') => 'primary',
      t('Import') => 'primary',
      t('Restore') => 'primary',
      t('Rebuild') => 'primary',
      t('Search') => 'primary',
      t('Add') => 'primary',
      t('Finish') => 'primary',
      t('Update') => 'info',
      t('Preview') => 'info',
      t('Execute') => 'info',
      t('Continue') => 'info',
      t('Generate') => 'info',
      t('Upload') => 'info',
      t('Reset') => 'warning',
      t('Unpublish') => 'warning',
      t('Clone') => 'warning',
      t('Back') => 'warning',
      t('Cancel') => 'warning',
      t('Delete') => 'danger',
      t('Remove') => 'danger',
    );
    foreach ($classes as $search => $class) {
      if (strpos($vars['element']['#value'], $search) !== FALSE) {
        $vars['element']['#attributes']['class'][] = $class;
        break;
      }
    }
  }
}


function gumby_textfield($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'text';
  element_set_attributes($element, array('id', 'name', 'value', 'size', 'maxlength'));
  _form_set_class($element, array('text input textarea'));

 /*
 $extra = '';
  if ($element['#autocomplete_path'] && drupal_valid_path($element['#autocomplete_path'])) {
    drupal_add_library('system', 'drupal.autocomplete');
    $element['#attributes']['class'][] = 'form-	autocomplete';

    $attributes = array();
    $attributes['type'] = 'hidden';
    $attributes['id'] = $element['#attributes']['id'] . '-autocomplete';
    $attributes['value'] = url($element['#autocomplete_path'], array('absolute' => TRUE));
    $attributes['disabled'] = 'disabled';
    $attributes['class'][] = 'autocomplete';
    $extra = '<input' . drupal_attributes($attributes) . ' />';
  }
*/

  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';

 //return $output . $extra;
  return $output;
}

function gumby_textarea($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id', 'name', 'cols', 'rows'));
  _form_set_class($element, array('form-textarea input textarea'));

  $wrapper_attributes = array(
    'class' => array('form-textarea-wrapper'),
  );

  // Add resizable behavior.
  if (!empty($element['#resizable'])) {
    drupal_add_library('system', 'drupal.textarea');
    $wrapper_attributes['class'][] = 'resizable';
  }

  $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
  $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
  $output .= '</div>';
  return $output;
}



function gumby_password($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'password';
  element_set_attributes($element, array('id', 'name', 'size', 'maxlength'));
  _form_set_class($element, array('text input password form-text'));

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

/**
 * Returns HTML for a button form element.
 */
function gumby_button($variables) {
  $element = $variables['element'];
  $label = $element['#value'];
  element_set_attributes($element, array('id', 'name', 'value', 'type'));
	//_form_set_class($element, array('btn pretty rounded medium'));
	
  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }

  // Prepare input whitelist - added to ensure ajax functions don't break
  $whitelist = _gumby_element_whitelist();

  if (isset($element['#id']) && in_array($element['#id'], $whitelist)) {
    return '<input' . drupal_attributes($element['#attributes']) . ">\n"; // This line break adds inherent margin between multiple buttons
  }
  else {
    return '<button' . drupal_attributes($element['#attributes']) . '>'. $label ."</button>\n"; // This line break adds inherent margin between multiple buttons
  }
}

function gumby_checkbox($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'checkbox';
  element_set_attributes($element, array('id', 'name','#return_value' => 'value'));

  // Unchecked checkbox has #value of integer 0.
  if (!empty($element['#checked'])) {
    $element['#attributes']['checked'] = 'checked';
  }
  _form_set_class($element, array('form-checkbox'));

  return '<input' . drupal_attributes($element['#attributes']) . ' /><span></span>';
}

function gumby_radio($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'radio';
  element_set_attributes($element, array('id', 'name','#return_value' => 'value'));

  if (isset($element['#return_value']) && $element['#value'] !== FALSE && $element['#value'] == $element['#return_value']) {
    $element['#attributes']['checked'] = 'checked';
  }
  _form_set_class($element, array('form-radio'));

  return '<input' . drupal_attributes($element['#attributes']) . ' /><span><i class="icon-dot"></i></span>';
}

function gumby_select($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id', 'name', 'size'));
  _form_set_class($element, array('form-select'));

  return '<div class="picker"><select' . drupal_attributes($element['#attributes']) . '>' . form_select_options($element) . '</select></div>';
}

/**
 * Format the output of Webform components.
 */
function gumby_webform_display_textfield($variables) {
  $element = $variables['element'];
  $prefix = $element['#format'] == 'html' ? '' : $element['#field_prefix'];
  $suffix = $element['#format'] == 'html' ? '' : $element['#field_suffix'];
  $value = $element['#format'] == 'html' ? check_plain($element['#value']) : $element['#value'];
  return $value !== '' ? ($prefix . $value . $suffix) : ' ';
  _form_set_class($element, array('text input'));
}

/**
 * Format the output of Webform components.
 */
function gumby_webform_display_textarea($variables) {
  $element = $variables['element'];
  $output = $element['#format'] == 'html' ? nl2br(check_plain($element['#value'])) : $element['#value'];
  if (drupal_strlen($output) > 80) {
    $output = ($element['#format'] == 'html') ? '<div class="text input webform-long-answer">' . $output . '</div>' : $output;
  }
  return $output !== '' ? $output : ' ';
}

/**
 * Theme function to render an email component.
 */
function gumby_webform_email($variables) {
  $element = $variables['element'];

  // This IF statement is mostly in place to allow our tests to set type="text"
  // because SimpleTest does not support type="email".
  if (!isset($element['#attributes']['type'])) {
    $element['#attributes']['type'] = 'email';
  }

  // Convert properties to attributes on the element if set.
  foreach (array('id', 'name', 'value', 'size') as $property) {
    if (isset($element['#' . $property]) && $element['#' . $property] !== '') {
      $element['#attributes'][$property] = $element['#' . $property];
    }
  }
  _form_set_class($element, array('text input form-text', 'form-email'));

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}




/**
 * Returns an array containing ids of any whitelisted drupal elements
 */
function _gumby_element_whitelist() {
/**
 * Why whitelist an element?
 * The reason is to provide a list of elements we wish to exclude
 * from certain modifications made by the gumby theme which
 * break core functionality - e.g. ajax.
 */
  return array(
    'edit-refresh',
    'edit-pass-pass1',
    'edit-pass-pass2',
    'panels-ipe-cancel',
    'panels-ipe-customize-page',
    'panels-ipe-save',
  );
}

function gumby_gumby_append_element(&$variables) {
  $element = &$variables['element'];

  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }

  $exclude_control = FALSE;
  $control_wrapper = '<div class="field">';
  // Add gumby class
  if ($element['#type'] == "radio" || $element['#type'] == "checkbox" || $element['#type'] == "tableselect" || isset($element['#exclude_control'])) {
    $exclude_control = TRUE;
  }
  else {
    $attributes['class'] = array('control-group');
  }

  // Check for errors and set correct error class
  if (isset($element['#parents']) && form_get_error($element)) {
    $attributes['class'][] = 'error';
  }

  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }


  if (isset($element['#field_prefix'])) {
    $attributes['class'][] = 'input-prepend';
  }

  if (isset($element['#field_suffix'])) {
    $attributes['class'][] = 'input-append';
  }

  $attributes['class'][] = 'form-item';
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? $element['#field_prefix'] : '';
  $suffix = isset($element['#field_suffix']) ? $element['#field_suffix'] : '';

  // Prepare input whitelist - added to ensure ajax functions don't break
  $whitelist = _gumby_element_whitelist();

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      // Check if item exists in element whitelist
      if (isset($element['#id']) && in_array($element['#id'], $whitelist)) {
        $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
        $exclude_control = TRUE;
      }
      else {
        $output = $exclude_control ? $output : $output.$control_wrapper;
        $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      }
      break;

    case 'after':
      $output = $exclude_control ? $output : $output.$control_wrapper;
      $variables['#children'] = ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output = $exclude_control ? $output : $output.$control_wrapper;
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if ( !empty($element['#description']) ) {
    $output .= '<p class="help-block">' . $element['#description'] . "</p>\n";
  }

  // Check if control wrapper was added to ensure we close div correctly
  if ($exclude_control) {
    $output .= "</div>\n";
  }
  else {
    $output .= "</div></div>\n";
  }
  return $output;
}
