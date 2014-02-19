<?php
/**
 * @file
 * menu-tree.func.php
 */

/**
 * Overrides theme_menu_tree().
 */
function gumby_menu_tree(&$variables) {
  return '<ul class="menu nav">' . $variables['tree'] . '</ul>';
}

/**
 * gumby theme wrapper function for the primary menu links.
 */
function gumby_menu_tree__primary(&$variables) {
  return '<ul class="menu navbar">' . $variables['tree'] . '</ul>';
}

/**
 * gumby theme wrapper function for the secondary menu links.
 */
function gumby_menu_tree__secondary(&$variables) {
  return '<ul class="menu navbar secondary">' . $variables['tree'] . '</ul>';
}
