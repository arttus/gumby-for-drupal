<?php
/**
 * @file
 * page.vars.php
 */

/**
 * Implements hook_preprocess_page().
 *
 * @see page.tpl.php
 */

function gumby_preprocess_page(&$variables) {

  // Format and add main menu to theme
  $main_menu_tree = menu_tree_all_data('main-menu');
  $variables['main_menu'] = menu_tree_output($main_menu_tree);

  // Primary nav
  $variables['primary_nav'] = FALSE;
  if ($variables['main_menu']) {
    // Build links
    
    $variables['primary_nav'] = menu_tree(variable_get('menu_main_links_source', 'main-menu'));
    // Provide default theme wrapper function
    $variables['primary_nav']['#theme_wrappers'] = array('menu_tree__primary');
  }

  // Secondary nav
  $variables['secondary_nav'] = FALSE;
  if ($variables['secondary_menu']) {
    // Build links
    $variables['secondary_nav'] = menu_tree(variable_get('menu_secondary_links_source', 'user-menu'));
    // Provide default theme wrapper function
    $variables['secondary_nav']['#theme_wrappers'] = array('menu_tree__secondary');
  }
  
  //gumby copyright 
  $variables['copyright'] = t('Made with <a href="http://www.drupal.org" target="_blank">Drupal</a> and <a href="http://www.gumbyframework.com" target="_blank">Gumby</a>');
  
}
