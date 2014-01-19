<?php
/*
 * Custom theme functions
 *
 */

/**
 * A wrapper function for gumby_theme_get_settings().
 * 
 * @param $name
 *   The name of the setting that you want to retrieve. 
 * @param $default (optional)
 *   The name (key) of the theme that you want to fetch the
 *   setting for. Defaults to NULL.   
 * @param $theme (optional)
 *   The key (machin-readable name) of a theme. Defaults to the key of the
 *   current theme if not defined.
 *   
 * @see 
 *   gumby_theme_get_setting().
 */
function gumby_theme_get_setting($name, $theme = NULL) {
  switch ($name) {
    case 'exclude':
      $setting = gumby_theme_get_info($name, $theme);
      break;
    default:
      $setting = theme_get_setting($name, $theme);
      break;
  }

  return isset($setting) ? $setting : NULL; 
}

function gumby_get_settings($theme = NULL) {
  if (!isset($theme)) {
    $theme = !empty($GLOBALS['theme_key']) ? $GLOBALS['theme_key'] : '';
  }

  if ($theme) {
    $themes = list_themes();
    $theme_object = $themes[$theme];
  }

  return $theme_object->info['settings'];
}

function gumby_theme_get_info($setting_name, $theme = NULL) {
  // If no key is given, use the current theme if we can determine it.
  if (!isset($theme)) {
    $theme = !empty($GLOBALS['theme_key']) ? $GLOBALS['theme_key'] : '';
  }

  $output = array();

  if ($theme) {
    $themes = list_themes();
    $theme_object = $themes[$theme];

    // Create a list which includes the current theme and all its base themes.
    if (isset($theme_object->base_themes)) {
      $theme_keys = array_keys($theme_object->base_themes);
      $theme_keys[] = $theme;
    }
    else {
      $theme_keys = array($theme);
    }

    foreach ($theme_keys as $theme_key) {
      if (!empty($themes[$theme_key]->info[$setting_name])) {
        $output[$setting_name] = $themes[$theme_key]->info[$setting_name];
      }
    }
  }
  return $output;
}


/**
 * Returns HTML for a set of links.
 */
function theme_gumby_links($variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];

  global $language_url;
  $output = '';

  if (count($links) > 0) {
    $output = '';
    $output .= '<ul' . drupal_attributes($attributes) . '>';
    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $heading = array(
          'text' => $heading,
          // Set the default level of the heading.
          'level' => 'li',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $children = array();

      if (isset($link['below'])) {
        $children = $link['below'];
      }

      $attributes = array('class' => array($key));

      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_links) {
        $attributes['class'][] = 'last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
        && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $attributes['class'][] = 'active';
      }

      if (count($children) > 0) {
        $attributes['class'][] = 'dropdown';
        $link['attributes']['data-toggle'] = 'dropdown';
        $link['attributes']['class'][] = 'dropdown-toggle';
      }

      if (!isset($link['attributes'])) {
        $link['attributes'] = array();
      }

      $link['attributes'] = array_merge($link['attributes'], $attributes);

      if (count($children) > 0) {
        $link['attributes']['class'][] = 'dropdown';
      }

      $output .= '<li' . drupal_attributes($attributes) . '>';

      if (isset($link['href'])) {
        if (count($children) > 0) {
          $link['html'] = TRUE;
          $link['title'] .= ' <span class="caret"></span>';
          $output .=  '<a' . drupal_attributes($link['attributes']) . ' href="#">'. $link['title'] .'</a>';
        }
        else {
          // Pass in $link as $options, they share the same keys.
          $output .= l($link['title'], $link['href'], $link);
        }
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }

        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }

      $i++;

      if(count($children) > 0) {
        $attributes = array();
        $attributes['class'] = array('dropdown-menu');

        $output .= theme('gumby_links', array('links' => $children, 'attributes' => $attributes));
      }

      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;
}

/*
 * Overwrites the default item list to make it prettier
 */
function gumby_item_list($variables) {
  $items = $variables['items'];
  $title = $variables['title'];
  $type = $variables['type'];
  $attributes = $variables['attributes'];
  $output = '';

  if (isset($title)) {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    $i = 0;
    foreach ($items as $item) {
      $attributes = array();
      $children = array();
      $data = '';
      $i++;
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $data .= theme('item_list', array('items' => $children, 'title' => NULL, 'type' => $type, 'attributes' => $attributes));
      }
      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items) {
        $attributes['class'][] = 'last';
      }
      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>\n";
    }
    $output .= "</$type>";
  }

  return $output;
}

/**
 * Implements hook_js_alter().
 */


function _gumby_alter($files, $type) {
  $output = array();

  foreach($files as $key => $value) {
    if (isset($files[$key][$type])) {
      foreach ($files[$key][$type] as $file => $name) {
        $output[$name] = FALSE;
      }
    }
  }
  return $output;
}

