<div class="taylor-flipped clearfix <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['header']): ?>
    <div class="row">
      <div class="twelve columns header">       
          <?php print $content['header']; ?>
      </div>
    </div>
  <?php endif; ?>

  <div class="row">
    <div class="three columns sidebar panel-panel">      
        <?php print $content['quarter1']; ?>
    </div>
    <div class="three columns sidebar panel-panel">    
        <?php print $content['quarter2']; ?>
    </div>
    <div class="six columns content panel-panel">     
        <?php print $content['half']; ?>
    </div>
  </div>
  
  <?php if ($content['footer']): ?>
    <div class="row">
      <div class="twelve columns footer">        
          <?php print $content['footer']; ?>
      </div>
    </div>
  <?php endif; ?>

</div><!-- /.taylor -->
