<div class="taylor-flipped clearfix <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="row">
    <div class="eight columns content">
      <?php if ($content['header']): ?>
        <div class="row">
          <div class="twelve header columns">           
              <?php print $content['header']; ?>
          </div>
        </div>
      <?php endif; ?>

      <div class="row">
        <div class="three sidebar columns">         
          <?php print $content['quarter1']; ?>
        </div>
        <div class="three sidebar columns">         
          <?php print $content['quarter2']; ?>
        </div>
        <div class="six content columns">          
          <?php print $content['half']; ?>
        </div>
      </div>
      
      <?php if ($content['footer']): ?>
        <div class="row">
          <div class="twelve footer columns">            
            <?php print $content['footer']; ?>
          </div>
        </div>
      <?php endif; ?>
    </div>

    <div class="four columns sidebar">
      <div class="row">
        <div class="twelve footer columns">          
          <?php print $content['sidebar']; ?>
        </div>
      </div>
    </div>
  </div>
 
</div><!-- /.taylor-flipped -->