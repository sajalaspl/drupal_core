<?php
// $Id: privatemsg-recipients.tpl.php,v 1.1 2010/07/24 07:36:21 sajal Exp $
// Each file loads it's own styles because we cant predict which file will be
// loaded.
drupal_add_css(drupal_get_path('module', 'privatemsg') . '/styles/privatemsg-recipients.css');
?>
<div class="message-participants">
  <?php print $participants; ?>
</div>