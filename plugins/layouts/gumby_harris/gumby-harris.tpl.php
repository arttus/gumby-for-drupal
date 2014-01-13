<div class="harris clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="row">
    <div class="twelve columns header">
      <?php print $content['header']; ?>
    </div>
  </div>
  
  <div class="row">
    <div class="three columns sidebar">      
      <?php print $content['column1']; ?>
    </div>
    <div class="six columns content">     
      <?php print $content['contentmain']; ?>
    </div>
    <div class="three columns sidebar">     
      <?php print $content['column2']; ?>
    </div>
  </div>  
</div><!-- /.harris -->
