<div class="selby clearfix <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
 <div class="four columns sidebar">
    <div class="row">
      <div class="twelve sidebar columns">          
        <?php print $content['sidebar']; ?>
      </div>
    </div>
  </div>
	<div class="eight columns content">
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
	</div>

</div><!-- /.selby-->
