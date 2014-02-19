<?php
/**
 * @file
 *
 * Theme implementation to display the header block on a Drupal page.
 *
 * This utilizes the following variables thata re normally found in
 * page.tpl.php:
 * - $logo
 * - $front_page
 * - $site_name
 * - $front_page
 * - $site_slogan
 * - $search_box
 *
 * Additional items can be added via theme_preprocess_pane_header(). See
 * template_preprocess_pane_header() for examples.
 */
 ?>

<?php if (!empty($logo)): ?>
  <a class="three columns logo" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" >
    <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
  </a>
<?php endif; ?>

<?php if (!empty($site_slogan)): ?>
  <div id="site-slogan"><?php print $site_slogan; ?></div>
<?php endif; ?>

<?php if (!empty($search_box)): ?>
  <div id="search-box"><?php print $search_box; ?></div>
<?php endif; ?>
