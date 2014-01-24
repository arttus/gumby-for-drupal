<?php
/**
 * @file
 * Gumby Now more flexible than ever for Drupal front-end development.
 *  
 */
 
// Provide < PHP 5.3 support for the __DIR__ constant.
if (!defined('__DIR__')) {
  define('__DIR__', dirname(__FILE__));
}
require_once __DIR__ . '/includes/gumby.inc';
require_once __DIR__ . '/includes/theme.inc';
require_once __DIR__ . '/includes/form.inc';
require_once __DIR__ . '/includes/menu.inc';
require_once __DIR__ . '/includes/pager.inc';
require_once __DIR__ . '/includes/item-list.inc';
require_once __DIR__ . '/includes/links.inc';

/**
 * Implementation of template_preprocess_html()
 */
 
function gumby_preprocess_html(&$variables) {
 	$path_to_gumby = drupal_get_path('theme', 'gumby');
  // add meta for Gumby Responsive
  // <meta name="viewport" content="width=device-width, initial-scale=1.0"> hardcoded in html.tpl for now
  $element = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport', 
      'content' => 'width=device-width, initial-scale=1.0',
    ),
  );
  drupal_add_html_head($element, 'gumby_responsive');
}


 
/**
 * Implements template_preprocess_page().
 */

function gumby_preprocess_page(&$variables) {

  // Add search_form to theme
  $variables['search_form'] = '';
  if (module_exists('search') && user_access('search content')) {
    $search_box_form = drupal_get_form('search_form');
    $search_box_form['basic']['keys']['#title'] = '';
    $search_box_form['basic']['keys']['#attributes'] = array('placeholder' => 'Search');
    $search_box_form['basic']['keys']['#attributes']['class'][] = 'search-query';
    $search_box_form['basic']['submit']['#value'] = t('Search');
    $search_box_form['#attributes']['class'][] = 'navbar-form';
    $search_box_form['#attributes']['class'][] = 'pull-right';
    $search_box = drupal_render($search_box_form);
    $variables['search_form'] = (user_access('search content')) ? $search_box : NULL;
  }

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
  
  // Primary nav.
  $variables['primary_nav'] = FALSE;
  if ($variables['main_menu']) {
    // Build links.
    $variables['primary_nav'] = menu_tree(variable_get('menu_main_links_source', 'main-menu'));
    // Provide default theme wrapper function.
    $variables['primary_nav']['#theme_wrappers'] = array('menu_tree__primary');
  }

  // Secondary nav.
  $variables['secondary_nav'] = FALSE;
  if ($variables['secondary_menu']) {
    // Build links.
    $variables['secondary_nav'] = menu_tree(variable_get('menu_secondary_links_source', 'user-menu'));
    // Provide default theme wrapper function.
    $variables['secondary_nav']['#theme_wrappers'] = array('menu_tree__secondary');
  }

  //gumby copyright 
  $variables['copyright'] = 'Made with <a href="http://www.drupal.org" target="_blank">Drupal</a> and <a href="http://www.gumbyframework.com" target="_blank">Gumby</a>';
}


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

/**
 * Adds the search form's submit button right after the input element.
 *
 * @ingroup themable
 */
function gumby_search_form_wrapper(&$variables) {
  $output = '<div class="input-append">';
  $output .= $variables['element']['#children'];
  $output .= '<button type="submit" class="btn">';
  $output .= '<i class="icon-search"></i>';
  $output .= '<span class="element-invisible">' . t('Search') . '</span>';
  $output .= '</button>';
  $output .= '</div>';
  return $output;
 }


/**
 * Implements theme_menu_link().
 */
function gumby_link($variables) {
  $icons = '';
  if (isset($variables['options']['attributes']['class']) && is_array($variables['options']['attributes']['class'])) {
    $css_classes = $variables['options']['attributes']['class'];
    if ($icon_classes = preg_grep('/^icon\-.*/', $css_classes)) {
      // render an icon for each class
      foreach ($icon_classes as $icon_class) {
        $icons .= '<i class="' . $icon_class . '"></i>';
      }
      // unset icon classes for attributes to prevent double rendering
      $variables['options']['attributes']['class'] = array_diff($css_classes, $icon_classes);
    }
  }
  return '<a href="' . check_plain(url($variables['path'], $variables['options'])) . '"' . drupal_attributes($variables['options']['attributes']) . '>' . $icons . '<span>' . ($variables['options']['html'] ? $variables['text'] : check_plain($variables['text'])) . '</span>' .  '</a>';
}


//remove panel seperator
function gumby_panels_default_style_render_region($vars) {
    $output = '';
    $output .= implode('', $vars['panes']);
    return $output;
}


