<?php
/**
 * @file
 * html.vars.php
 *
 * @see html.tpl.php
 */


function gumby_preprocess_html(&$variables) {
 	$path_to_gumby = drupal_get_path('theme', 'gumby');
  // add meta for Gumby Responsive
  // <meta name="viewport" content="width=device-width, initial-scale=1.0">
  $element = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport', 
      'content' => 'width=device-width, initial-scale=1.0',
    ),
  );
  
  drupal_add_html_head($element, 'gumby_responsive');
  
/*
  switch (theme_get_setting('gumby_navbar_position')) {
    case 'fixed-top':
      $variables['classes_array'][] = 'navbar-is-fixed-top';
      break;

    case 'fixed-bottom':
      $variables['classes_array'][] = 'navbar-is-fixed-bottom';
      break;

    case 'static-top':
      $variables['classes_array'][] = 'navbar-is-static-top';
      break;
  }
*/

}