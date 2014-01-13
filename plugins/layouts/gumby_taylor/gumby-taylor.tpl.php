<div class="taylor clearfix <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="row">
    <div class="twelve columns header">      
      <?php print $content['header']; ?>
    </div>
  </div>

  <div class="row">
    <div class="six columns content">     
      <?php print $content['half']; ?>
    </div>
    <div class="three columns sidebar">    
      <?php print $content['quarter1']; ?>
    </div>
    <div class="three columns sidebar">    
      <?php print $content['quarter2']; ?>
    </div>
  </div>
  
  <div class="row">
    <div class="twelve columns footer">     
      <?php print $content['footer']; ?>
    </div>
  </div>

</div><!-- /.taylor -->
