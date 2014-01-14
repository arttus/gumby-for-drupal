<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 */
?>

<div class="container">
<header id="header" class="twelve columns pretty navbar" role="header">			
	<div class="row">	
		  <?php if (!empty($logo)): ?>
        <a class="three columns logo" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" >
          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        </a>
      <?php endif; ?>

			
		  <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
		<a class="toggle" gumby-trigger="#main-menu > ul" href="/"><i class="icon-menu"></i></a> 
	  <div class="nav-collapse nav-menu-collapse">
		    <div class="inner"> 
		      <?php if ($main_menu): ?>
		        <nav id="main-menu" class="six columns main-menu" role="navigation">
		          <?php print render($main_menu); ?>
		        </nav> <!-- /#main-menu -->
		      <?php endif; ?>		 
					</div>
		  </div>
 
		
		  <?php if ($search_form): ?>
		   <div class="search input two columns">
		    <?php print $search_form; ?>
		    </div>
		  <?php endif; ?>
    </div>
</header>

<div class="wrapper">
  <div class="row">
    <?php if ($breadcrumb): ?>
      <div id="breadcrumb" class="visible-desktop">
        <?php print $breadcrumb; ?>
      </div>
    <?php endif; ?>
    <?php if ($messages): ?>
      <div id="messages"> 
        <?php print $messages; ?>
      </div>
    <?php endif; ?>
    <div id="content">
      <a id="main-content"></a>
      <div id="page-header">
      
        <?php if ($title): ?>
          <div class="page-header">
            <h1 class="title"><?php print $title; ?></h1>
          </div>
        <?php endif; ?>
        <?php if ($tabs): ?>
          <div class="tab-nav">
            <?php print render($tabs); ?>
          </div>
        <?php endif; ?>
        <?php if ($action_links): ?>
          <ul class="pill tabs">
            <?php print render($action_links); ?>
          </ul>
        <?php endif; ?>            
 
      </div>
      <?php print render($page['content']); ?>  
    </div>   
  </div>
</div> <!-- /#main-wrapper -->

<footer id="footer" class="footer" role="footer">
  <div class="row">
    <?php if ($copyright): ?>
      <small class="copyright"><?php print $copyright; ?></small>
    <?php endif; ?><br/>
  </div>
</footer>
</div>