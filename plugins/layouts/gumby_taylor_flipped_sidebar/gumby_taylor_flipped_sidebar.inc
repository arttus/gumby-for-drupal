<?php
// Plugin definition
$plugin = array(
  'title' => t('Gumby Taylor Flipped Sidebar'),
  'icon' => 'gumby-taylor-flipped-sidebar.png',
  'category' => t('Gumby'),
  'theme' => 'gumby_taylor_flipped_sidebar',
  'regions' => array(
    'header' => t('Header'),
    'quarter1' => t('Quarter 1 Column'),
    'quarter2' => t('Quarter 2 Column'),
    'half' => t('Half Column'),
    'sidebar' => t('Sidebar'),
    'footer' => t('Footer'),
  ),
);
