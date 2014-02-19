<?php
/**
 * @file
 * gumby-search-form-wrapper.func.php
 */

/**
 * Theme function implementation for gumby_search_form_wrapper.
 */
function gumby_gumby_search_form_wrapper($variables) {
  $output = '<div class="field append">';
  $output .= $variables['element']['#children'];
  $output .= '<button type="submit" class="btn pretty default medium rounded">';
  $output .= '<i class="icon-search scale-lg"></i>';
  $output .= '<span class="element-invisible">' . t('Search') . '</span>';
  $output .= '</button>';
  $output .= '</div>';
  return $output;
}
