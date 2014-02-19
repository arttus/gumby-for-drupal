<?php
/**
 * @file
 * select.func.php
 */

/**
 * Overrides theme_select().
 */

function gumby_select($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id', 'name', 'size'));
  //_form_set_class($element, array('form-select'));

  return '<div class="picker"><select' . drupal_attributes($element['#attributes']) . '>' . form_select_options($element) . '</select></div>';
}