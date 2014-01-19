<div class="Phelan clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
	<div class="row">
    <div class="six columns content">      
      <?php print $content['contentleft']; ?>
    </div>
    <div class="six columns content">      
      <?php print $content['contentright']; ?>
    </div>
  </div>
</div><!-- /.phelan -->