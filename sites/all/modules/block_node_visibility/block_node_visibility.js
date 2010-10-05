/* $Id: block_node_visibility.js,v 1.1 2010/10/04 06:47:44 sajal Exp $ */

if (Drupal.jsEnabled) {
  $(document).ready(function() {
    $('#edit-block-node-visibility-enabled').click(function() {
      if ($(this).attr('checked')) {
        $('#block_node_visibility_settings').slideDown();
        $('#page_vis_settings').hide();
      }
      else {
        $('#block_node_visibility_settings').slideUp();
        $('#page_vis_settings').show();
      }
    });

    // init
    if ($('#edit-block-node-visibility-enabled').attr('checked')) {
      $('#page_vis_settings').hide();
    }
    else {
      $('#block_node_visibility_settings').hide();
    }

  });
}
