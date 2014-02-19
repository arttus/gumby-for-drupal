<?php
/**
 * @file
 * button.func.php
 */

/**
 * Overrides theme_button().
 */
function gumby_button($variables) {
  $element = $variables['element'];
  $label = $element['#value'];
  element_set_attributes($element, array('id', 'name', 'value', 'type'));
  
  // If a button type class isn't present then add in default.
  $button_classes = array(
    'default',
    'primary',
    'success',
    'info',
    'warning',
    'danger',
    'link',
  );
  $class_intersection = array_intersect($button_classes, $element['#attributes']['class']);
  if (empty($class_intersection)) {
    $element['#attributes']['class'][] = 'default';
  }

  // Add in the button type class.
  $element['#attributes']['class'][] = 'form ' . $element['#button_type'];

  // This line break adds inherent margin between multiple buttons.
  return '<button' . drupal_attributes($element['#attributes']) . '>' . $label . "</button>\n";
}
