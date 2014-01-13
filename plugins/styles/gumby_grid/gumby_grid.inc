<?php

$plugin = array(
  'title' => t('gumby grid'),
  'description' => t('Wraps panels or panes in a grid.'),
  'render panel' => 'gumby_grid_render_panel',
  'render pane' => 'gumby_grid_render_pane',
  'settings form' => 'gumby_grid_settings_form',
  'pane settings form' => 'gumby_grid_settings_form',
  'hook theme' => array(
    'gumby_grid' => array(
      'arguments' => array('content' => NULL, 'attributes' => array()),
    ),
  ),
);

/**
 * Theme function for a grid.
 */
function theme_gumby_grid($content, $attributes) {  
  if (!empty($content)) {
    return '<div ' . drupal_attributes($attributes) . '>' . $content . '</div>';
  }
}

/**
 * Theme function for the panel style.
 */
function theme_gumby_grid_render_panel($display, $panel_id, $panes, $settings) { 
  $output = '';
  foreach ($panes as $pane_id => $pane) {
    $output .= panels_render_pane($pane, $display->content[$pane_id], $display);
  }
  $attributes = gumby_grid_parse_settings($settings);
  return theme('gumby_grid', $output, $attributes);
}

/**
 * Theme function for the pane style.
 *
 * To save some markup, we merge our settings into the pane CSS settings.
 */

//function theme_gumby_grid_render_pane($content, $pane, $display) {
function theme_gumby_grid_render_pane($vars) {  
  $attributes = gumby_grid_parse_settings($vars['pane']->style['settings']);  
  foreach ($attributes as $attribute => $value) {
    if (empty($vars['content']->{"css_$attribute"})) {
      $vars['content']->{"css_$attribute"} = $value;
    }
    else {
      $vars['content']->{"css_$attribute"} .= ' ' . $value;
    }
  }
  
  return theme('panels_pane', $vars);
}

/**
 * Helper function for parsing an settings array.
 */
function gumby_grid_parse_settings($settings) {

  $attributes = array();
  $classes = array();
 // $id = array();
  $gumby_options = gumby_grid_get_options('columns');

  foreach ($settings as $key => $value) {
    if (!empty($value) || $value == '0') {
      

      if ($key == 'class') {
        $classes[] = $value;
      }
      
      if ($key == 'id') {
        $id = $value;
      }
      
      if (in_array($key, array('columns', 'pad', 'push', 'pull'))) {
        if($key == 'columns') {
		  $classes[] =  $gumby_options[$value]. " " .$key;
		}
 		else $classes[] = $key . '_' . $gumby_options[$value];
      }
      if (in_array($key, array('centered'))) {      	
        if($value == 1) $classes[] = $key;
      }
      if (in_array($key, array('alpha', 'omega'))) {      	
        if($value == 1) $classes[] = $key;
      }
      
    }
  }
  $classes = implode(' ', $classes);


  if (!empty($id)) {
    $attributes['id'] = $id;
  }

  if (!empty($classes)) {
    $attributes['class'] = $classes;
  }
  
  
  return $attributes;
}

/**
 * Helper function for options.
 */
function gumby_grid_get_options($key) {
  if (!in_array($key, array('columns', 'pad', 'push', 'pull'))) {
    return array();
  }
  
  $options = array('' => t('none')) + array('one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen');
  
  return $options;
}

/**
 * Helper function for the setting forms.
 */
function gumby_grid_settings_form($settings) {
  $form = array();

  $form['id'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS id'),
    '#description' => t('Enter a string to be used as the id attribute.'),
    '#default_value' => isset($settings['id']) ? $settings['id'] : '',
  );

  $form['class'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS classes'),
    '#description' => t('Enter a string to be used as the class attribute. Additional classes will be added from the settings below.'),
    '#default_value' => isset($settings['class']) ? $settings['class'] : '',
  );

  $form['columns'] = array(
    '#type' => 'select',
    '#title' => t('Width'),
    '#description' => t('Choose the width for this element (measured in columns).'),
    '#options' => gumby_grid_get_options('columns'),
    '#default_value' => isset($settings['columns']) ? $settings['columns'] : '',
  );

  $form['pad'] = array(
    '#type' => 'select',
    '#title' => t('Padding'),
    '#description' => t('Choose how much to pad this element (measured in columns).'),
    '#options' => gumby_grid_get_options('pad'),
    '#default_value' => isset($settings['pad']) ? $settings['pad'] : '',
  );

  $form['push'] = array(
    '#type' => 'select',
    '#title' => t('Push'),
    '#description' => t('Choose how much to push this element (measured in columns).'),
    '#options' => gumby_grid_get_options('push'),
    '#default_value' => isset($settings['push']) ? $settings['push'] : '',
  );

  $form['pull'] = array(
    '#type' => 'select',
    '#title' => t('Pull'),
    '#description' => t('Choose how much to pull this element (measured in columns).'),
    '#options' => gumby_grid_get_options('pull'),
    '#default_value' => isset($settings['pull']) ? $settings['pull'] : '',
  );
  
  $form['centered'] = array(
    '#type' => 'checkbox',
    '#title' => t('Centered'),
    '#description' => t('Check if this element is centered.'),
    '#default_value' => isset($settings['centered']) ? $settings['centered'] : FALSE,
  );

  $form['alpha'] = array(
    '#type' => 'checkbox',
    '#title' => t('Alpha'),
    '#description' => t('Check if this is the first child element of another.'),
    '#default_value' => isset($settings['alpha']) ? $settings['alpha'] : FALSE,
  );

  $form['omega'] = array(
    '#type' => 'checkbox',
    '#title' => t('Omega'),
    '#description' => t('Check if this is the last child element of another.'),
    '#default_value' => isset($settings['omega']) ? $settings['omega'] : FALSE,
  );
  
  return $form;
}
