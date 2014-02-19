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
<div<?php print $attributes; ?>>
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
        <h4 class="modal-title"><?php print $heading; ?></h4>
      </div>
      <div class="modal-body"><?php print $body; ?></div>
      <div class="modal-footer"><?php print $footer; ?></div>
    </div>
  </div>
</div>

<div class="modal" id="modal1">
  <div class="content">
    <a class="close switch" gumby-trigger="|#modal1"><i class="icon-cancel" /></i></a>
    <div class="row">
      <div class="ten columns centered text-center">
        <h2>This is a modal.</h2>
        <p>Gumby modals are easy to make using Toggles &amp; Switches.</p>
        <p class="btn primary medium">
          <a href="#" class="switch" gumby-trigger="|#modal1">Close Modal</a>
        </p>
      </div>
    </div>
  </div>
</div>
<p class="btn primary medium"><a href="#" class="switch" gumby-trigger="#modal1">Open Modal</a></p>
