<?php
/**
 * @file
 * Template for Gumby Grid Freestyle.
 *
 *  Gumby freestyle uses a panels style plugin to create your own layouts
 * if your looking at this template you might be interested in checking out 
 * the panels plugin located @ plugins/styles/gumby_grid/gumby_grid.inc
 */
?>

<div class="grid freestyle clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="row">
    <?php print $content['contentmain']; ?>
  </div>
</div><!-- /. grid freestyle -->
