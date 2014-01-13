<div class="geary clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="row">
    <div class="twelve columns top">     
      <?php print $content['header']; ?>
    </div>
  </div>
  
  <div class="row">
    <div class="four columns sidebar">
      <?php print $content['column1']; ?>
    </div>
    <div class="four columns content">      
      <?php print $content['column2']; ?>
    </div>
    <div class="four columns sidebar">      
      <?php print $content['column3']; ?>
    </div>
  </div>
</div><!-- /.geary -->
