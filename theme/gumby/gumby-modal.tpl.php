<?php
/**
 * @file
 * gumby-modal.tpl.php
 *
 * Markup for gumby modals.
 *
 * Variables:
 * - $attributes: Attributes for the outer modal div.
 * - $heading: Modal title.
 * - $body: The rendered body of the modal.
 * - $footer: The rendered footer of the modal.
 */
?>

<div<?php print $attributes; ?> id="modal"> 
  <a class="close switch" gumby-trigger="|#modal1"><i class="icon-cancel" /></i></a>
  <div class="row">
    <div class="ten columns centered text-center">
    <div class="modal-header">
      <button type="button" class="close" gumby-trigger="|#modal" aria-hidden="true">&times;</button>
      <h4 class="modal-title"><?php print $heading; ?></h4>
    </div>
    <div class="modal-body"><?php print $body; ?></div>
    <div class="modal-footer"><?php print $footer; ?></div>
    </div>
  </div>
</div>
