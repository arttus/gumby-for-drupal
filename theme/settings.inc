<?php
/**
 * @file
 * settings.inc
 */

/**
 * Contains the form for the theme settings.
 *
 * @param array $form
 *   The form array, passed by reference.
 * @param array $form_state
 *   The form state array, passed by reference.
 */
function _gumby_settings_form(&$form, $form_state) {
 
  // Rebuild registry.
  $form['advanced']['gumby_rebuild_registry'] = array(
    '#type' => 'checkbox',
    '#title' => t('Rebuild theme registry on every page.'),
    '#default_value' => theme_get_setting('gumby_rebuild_registry'),
    '#description' => t('During theme development, it can be very useful to continuously !rebuild. !warning', array(
      '!rebuild' => l(t('rebuild the theme registry'), 'http://drupal.org/node/173880#theme-registry'),
      '!warning' => '<div class="alert alert-warning messages warning"><strong>' . t('WARNING') . ':</strong> ' . t('This is a huge performance penalty and must be turned off on production websites. ') . '</div>',
    )),
  );
  // Suppress jQuery message.
  $form['advanced']['gumby_toggle_jquery_error'] = array(
    '#type' => 'checkbox',
    '#title' => t('Suppress jQuery version error message'),
    '#default_value' => theme_get_setting('gumby_toggle_jquery_error'),
    '#description' => t('Enable this if the version of jQuery has been upgraded to 1.9+ using a method other than the !jquery_update module.', array(
      '!jquery_update' => l(t('jQuery Update'), 'https://drupal.org/project/jquery_update'),
    )),
  );

}
