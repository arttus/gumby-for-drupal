<div class="phoenix clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['header']): ?>
    <header class="row">
      <div class="twelve columns header">      
        <?php print $content['header']; ?>
      </div>
    </header>
  <?php endif; ?>

  <?php if ($content['contentmain']): ?>
    <div class="wrapper">
      <div class="row">
        <div class="twelve columns content">
          <?php print $content['contentmain']; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($content['footer']): ?>
    <footer class="row">
      <div class="twelve columns footer">        
        <?php print $content['footer']; ?>
      </div>
    </footer>
  <?php endif; ?>

</div>
