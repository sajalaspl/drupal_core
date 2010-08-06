<?php
// $Id: block.tpl.php,v 1.1.1.1 2010/06/25 06:06:11 bhargav Exp $
?>
<div class="<?php print "block block-$block->module" ?>" id="<?php print "block-$block->module-$block->delta"; ?>">
  <div class="title"><h3><?php print $block->subject ?></h3></div>
  <div class="content"><?php print $block->content ?></div>
</div>