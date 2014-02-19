<div class="container <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['header']): ?>
	<header id="header" class="twelve columns pretty navbar" role="header">			
		<div class="row">	
	     <?php print $content['header']; ?>
    </div>
   </header>
  <?php endif; ?>

  <?php if ($content['contentmain']): ?>
	<div class="wrapper">
  	<div class="row"> 
        <?php print $content['contentmain']; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($content['footer']): ?>
  <footer id="footer" class="footer" role="footer">
  	<div class="row">
      <?php print $content['footer']; ?>
    </div>
    
  </footer>
  <?php endif; ?>

</div>