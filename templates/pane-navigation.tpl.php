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
    <?php print render($main_menu); ?>
  </nav> <!-- /#main-menu -->
<?php endif; ?>

<?php if (!empty($secondary_menu)): ?>
  <div id="secondary" class="clearfix">
    <?php print $secondary_menu; ?>
  </div>
<?php endif; ?>
</div>
