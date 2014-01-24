<?php
/**
 * @file
 *
 * Theme implementation to display the messages area, which is normally
 * included roughly in the content area of a page.
 *
 * This utilizes the following variables thata re normally found in
 * page.tpl.php:
 * - $main_menu
 * - $secondary_menu
 * - $breadcrumb
 * - $mission
 *
 * Additional items can be added via theme_preprocess_pane_messages(). See
 * template_preprocess_pane_messages() for examples.
 */
 ?>
  <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
<a class="toggle btn-navbar " gumby-trigger="#main-menu > ul" href="/"><i class="icon-menu"></i></a> 
<div class="nav-collapse nav-menu-collapse">

<?php if (!empty($main_menu)): ?>
  <nav id="main-menu" class="six columns main-menu" role="navigation">
     <?php print $main_menu; ?>
     
     <?php if (!empty($primary_nav)): ?>
            <?php print render($primary_nav); ?>
          <?php endif; ?>
          <?php if (!empty($secondary_nav)): ?>
            <?php print render($secondary_nav); ?>
          <?php endif; ?>
          <?php if (!empty($page['navigation'])): ?>
            <?php print render($page['navigation']); ?>
          <?php endif; ?>

  </nav> <!-- /#main-menu -->
<?php endif; ?>
</div>
