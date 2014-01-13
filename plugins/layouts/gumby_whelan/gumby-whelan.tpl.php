<div class="whelan clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
	<div class="row">
	  <div class="three columns">    
	    <?php print $content['column1']; ?>
	  </div>
	  <div class="six columns">   
	    <?php print $content['contentmain']; ?>
	  </div>
	  <div class="three columns">   
	    <?php print $content['column2']; ?>
	  </div>
	</div> 
</div><!-- /.whelan -->
