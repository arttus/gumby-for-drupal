<div class="burr clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
	<div class="row">
    <div class="four columns sidebar">      
      <?php print $content['sidebar']; ?>
    </div>
    <div class="eight columns content">      
      <?php print $content['contentmain']; ?>
    </div>
  </div>
</div><!-- /.burr -->
