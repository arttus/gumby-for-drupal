<?php
/**
 * @file
 * views.vars.php
 */

/**
 * Implements hook_preprocess_views_view_table().
 */
function gumby_preprocess_views_view_table(&$vars) {
  $vars['classes_array'][] = 'table';
}
