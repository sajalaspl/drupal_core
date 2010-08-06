<?php 	drupal_add_js(drupal_get_path('module', 'userregihelper') .'/user-registration.js');
?>
<form action="/?q=user/register"  accept-charset="UTF-8" method="post" id="user-register">
	<div style="border:1px solid #FF0000">
		
		<div id='user-registration-terms-of-use'>
			<?php print drupal_render($form['terms_of_use']);?>
		</div>			
		<div id='user-registration-details' style="display:none;">
			<div id="messageBox" class="error" style="display:none;"></div>
			
			<!-- User Registration Form Start  -->
			<?php print drupal_render($form['account']['name']);?>

			<?php print drupal_render($form['account']['mail']);?>
			
			<?php print drupal_render($form['timezone']);?>
			<?php print drupal_render($form['form_build_id']);?>
			<?php print drupal_render($form['form_id']);?>
		
		
			<?php print drupal_render($form['Account information']['profile_firstname']);?>
			
			<?php print drupal_render($form['Account information']['profile_lastname']);?>
			
			<?php print drupal_render($form['Account information']['profile_secondaryemail']);?>
			
			<?php print drupal_render($form['Account information']['profile_address']);?>
			
			<?php print drupal_render($form['Account information']['profile_zip']);?>
			
			<?php print drupal_render($form['Account information']['profile_city']);?>
			
			<?php print drupal_render($form['Account information']['profile_country']);?>
			
			<?php print drupal_render($form['Account information']['profile_phone']);?>
			
			<?php print drupal_render($form['Account information']['profile_birthday']);?>
			
			<?php print drupal_render($form['Account information']['profile_gender']);?>
			
			<?php print drupal_render($form['Account information']['profile_usedinmarketing']);?>
			
			<?php print drupal_render($form['Account information']['profile_sendtoinbox']);?>

	
			<?php print drupal_render($form['captcha']);?>
			
			<?php print drupal_render($form['Account information']['send']);?>
			<?php print drupal_render($form['Account information']['_reset']);?>
		</div>
			
		<div id='user-registration-confirmation' style="display:none;">	
			<?php print $conformtaion_block; ?>
			<?php print drupal_render($form['submit']);?>
		</div>	
			<!-- input type="submit" name="op" id="edit-submit" value="Create new account"  class="form-submit" /-->
			
	</div>
</form>
