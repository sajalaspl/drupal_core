<?php
// $Id: box.tpl.php,v 1.1.1.1 2010/06/25 06:06:11 bhargav Exp $

/**
 * @file box.tpl.php
 *
 * Theme implementation to display a box.
 *
 * Available variables:
 * - $title: Box title.
 * - $content: Box content.
 *
 * @see template_preprocess()
 */
?>
<div class="box">

<?php if ($title): ?>
  <h2><?php print $title ?></h2>
<?php endif; ?>

  <div class="content"><?php print $content ?></div>
</div>
