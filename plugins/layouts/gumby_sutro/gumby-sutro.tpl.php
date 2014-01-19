<div class="sutro clearfix <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
	  <div class="row">
	    <header class="twelve columns header">      
	      <?php print $content['header']; ?>
	    </header>
	  </div>
	
	  <div class="row">
	    <div class="six columns content">     
	      <?php print $content['halfleft']; ?>
	    </div>
			<div class="six columns content">     
	      <?php print $content['halfright']; ?>
	    </div>
	  </div>
	  
	  <div class="row">
	    <footer class="twelve columns footer">     
	      <?php print $content['footer']; ?>
	    </footer
	  </div> 
</div><!-- /.sutro -->
