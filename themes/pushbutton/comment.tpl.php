<?php
// $Id: comment.tpl.php,v 1.1.1.1 2010/06/25 06:06:11 bhargav Exp $
?>
<div class="comment<?php print ' '. $status; ?>">
  <?php if ($picture) : ?>
    <?php print $picture ?>
  <?php endif; ?>
  <h3 class="title"><?php print $title ?></h3>
  <div class="submitted"><?php print $submitted ?><?php if ($comment->new) : ?><span class="new"> *<?php print $new ?></span><?php endif; ?></div>
  <div class="content">
    <?php print $content ?>
    <?php if ($signature): ?>
      <div class="clear-block">
        <div>—</div>
        <?php print $signature ?>
      </div>
    <?php endif; ?>
  </div>
  <!-- BEGIN: links -->
  <div class="links">&raquo; <?php print $links ?></div>
  <!-- END: links -->
</div>
