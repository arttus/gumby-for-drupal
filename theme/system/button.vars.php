<?php
/**
 * @file
 * button.vars.php
 */

/**
 * Implements hook_preprocess_button().
 */
function gumby_preprocess_button(&$vars) {
  $vars['element']['#attributes']['class'][] = 'btn pretty medium rounded';
  if (isset($vars['element']['#value'])) {
    if ($class = _gumby_colorize_button($vars['element']['#value'])) {
      $vars['element']['#attributes']['class'][] = $class;
    }
  }
}
