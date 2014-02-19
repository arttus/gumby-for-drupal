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
	        <a class="two columns logo" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" >
	          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
	        </a>
	      <?php endif; ?>
	            
		    <?php if (!empty($site_slogan)): ?>
		      <div id="site-slogan"><?php print $site_slogan; ?></div>
		    <?php endif; ?>
	
					  <div class="nav-collapse nav-menu-collapse">	  
			      <?php if ($main_menu): ?>
			        <nav id="main-menu" class="ten columns main-menu" role="navigation">
			          <?php print render($main_menu); ?>
			        </nav> <!-- /#main-menu -->
			      <?php endif; ?>		 
				  </div>
	 	
			  <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
				<a class="toggle" gumby-trigger="#main-menu > ul" href="/"><i class="icon-menu"></i></a> 

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
	<div class="three columns">
	 <h4 class="pane-title">Social</h4>
	<p><a href="http://www.linkedin.com/in/travisc" target="_blank"><i class="icon-linkedin-circled scale-2x pretty"></i></a><a href="https://twitter.com/arttus" target="_blank"><i class="icon-twitter-circled scale-2x"></i></a><a href="https://github.com/arttus" target="_blank"><i class="icon-github-circled scale-2x"></i></a><a href="https://plus.google.com/+TravisChristopher" target="_blank"><i class="icon-gplus-circled scale-2x"></i></a></p>
	</div>
	
	<div class="three columns">
	<h4 class="pane-title">Contact Us</h4>
	<p>63 Pearl St. Suite 130 <br/>Brooklyn, New York 11201<br>
	347-915-5749</p>
	</div>
	
	<div class="four columns">
	<h4 class="pane-title">Start today</h4>
	<p><a href="contact">Send a request</a> to get started today, operators are standing by. </p>
	</div>
	<div class="two columns padding_one">
	<h4 class="pane-title"></h4>
	<img src="/sites/all/themes/gumby/img/drupal-association.png">
	</div>
	</div>
		<div class="row">
	  <?php if ($copyright): ?>
	    <small class="copyright">Copyright &copy; Arttus inc. All rights reserved <?php print $copyright; ?></small>
	  <?php endif; ?><br/>
	  </div>
	</footer>
</div>