<?php
/**
 * @file
 * breadcrumb.func.php
 */

/**
 * Overrides theme_breadcrumb().
 *
 * Print breadcrumbs as an ordered list.
 */
/*
function gumby_breadcrumb($variables) {
  $output = '';
  $breadcrumb = $variables['breadcrumb'];

  // Determine if we are to display the breadcrumb.
  $gumby_breadcrumb = theme_get_setting('gumby_breadcrumb');
  if (($gumby_breadcrumb == 1 || ($gumby_breadcrumb == 2 && arg(0) == 'admin')) && !empty($breadcrumb)) {
    $output = theme('item_list', array(
      'attributes' => array(
        'class' => array('breadcrumb'),
      ),
      'items' => $breadcrumb,
      'type' => 'ol',
    ));
  }
  return $output;
}
*/

/**
 * Override theme_breadrumb().
 *
 * Print breadcrumbs as a list, with separators.
 */
function gumby_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb)) {
    $breadcrumbs = '<ul class="breadcrumb">';
    
    $count = count($breadcrumb) - 1;
    foreach ($breadcrumb as $key => $value) {
      if ($count != $key) {
        $breadcrumbs .= '<li>' . $value . '<span class="divider">/</span></li>';
      }
      else{
        $breadcrumbs .= '<li>' . $value . '</li>';
      }
    }
    $breadcrumbs .= '</ul>';
    
    return $breadcrumbs;
  }
}
