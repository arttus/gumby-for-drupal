<div class="barlett clearfix <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
	<div class="four columns sidebar">
    <div class="row">
      <div class="twelve sidebar columns">          
        <?php print $content['sidebar']; ?>
      </div>
    </div>
  </div>
	<div class="eight columns content">
		<?php if ($content['header']): ?>
		  <div class="row"> 
		    <header class="twelve columns content">
		      <?php print $content['header']; ?>
		    </header>   
	    </div>
	  <?php endif; ?>
    <div class="row">
      <div class="four sidebar columns">         
        <?php print $content['halfleft']; ?>
      </div>
      <div class="four sidebar columns">         
        <?php print $content['halfright']; ?>
      </div>
    </div>          
	</div>
</div><!-- /.barlett-->