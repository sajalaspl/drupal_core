<!-- h2>User Registration For ESS</h2>
<form action="/?q=user/register"  accept-charset="UTF-8" method="post" id="user-register">
<div>
	<fieldset><legend>Account information</legend>
		<div class="form-item" id="edit-name-wrapper">
 			<label for="edit-name">Username: <span class="form-required" title="This field is required.">*</span></label>
 			<input type="text" maxlength="60" name="name" id="edit-name" size="60" value="" class="form-text required" />
 			<div class="description">Spaces are allowed; punctuation is not allowed except for periods, hyphens, and underscores.</div>
		</div>
		<div class="form-item" id="edit-mail-wrapper">
			<label for="edit-mail">E-mail address: <span class="form-required" title="This field is required.">*</span></label>
 			<input type="text" maxlength="64" name="mail" id="edit-mail" size="60" value="" class="form-text required" />
 			<div class="description">A valid e-mail address. All e-mails from the system will be sent to this address. The e-mail address is not made public and will only be used if you wish to receive a new password or wish to receive certain news or notifications by e-mail.</div>
		</div>
	</fieldset>
	<input type="hidden" name="timezone" id="edit-user-register-timezone" value="19800"  />
	<input type="hidden" name="form_build_id" id="form-5c76985c664d524cf767ca91159934e7" value="form-5c76985c664d524cf767ca91159934e7"  />
	<input type="hidden" name="form_id" id="edit-user-register" value="user_register"  />
	
	<fieldset>
		<legend>Account information</legend>
		<div class="form-item" id="edit-profile-firstname-wrapper">
 			<label for="edit-profile-firstname">First name: <span class="form-required" title="This field is required.">*</span></label>
			<input type="text" maxlength="255" name="profile_firstname" id="edit-profile-firstname" size="60" value="" class="form-text required" />
		</div>
		
		<div class="form-item" id="edit-profile-lastname-wrapper">
 			<label for="edit-profile-lastname">Last name: <span class="form-required" title="This field is required.">*</span></label>
 				<input type="text" maxlength="255" name="profile_lastname" id="edit-profile-lastname" size="60" value="" class="form-text required" />
		</div>

		<div class="form-item" id="edit-profile-secondaryemail-wrapper">
 			<label for="edit-profile-secondaryemail">Secondary email address: </label>
 			<input type="text" maxlength="255" name="profile_secondaryemail" id="edit-profile-secondaryemail" size="60" value="" class="form-text" />
		</div>
		<div class="form-item" id="edit-profile-address-wrapper">
 			<label for="edit-profile-address">Address: <span class="form-required" title="This field is required.">*</span></label>
 			<textarea cols="60" rows="5" name="profile_address" id="edit-profile-address"  class="form-textarea resizable required"></textarea>
		</div>
		<div class="form-item" id="edit-profile-zip-wrapper">
 			<label for="edit-profile-zip">Zip: <span class="form-required" title="This field is required.">*</span></label>
 			<input type="text" maxlength="255" name="profile_zip" id="edit-profile-zip" size="60" value="" class="form-text required" />
		</div>
		
		<div class="form-item" id="edit-profile-city-wrapper">
 			<label for="edit-profile-city">City: <span class="form-required" title="This field is required.">*</span></label>
 			<input type="text" maxlength="255" name="profile_city" id="edit-profile-city" size="60" value="" class="form-text required" />
		</div>
	
		<div class="form-item" id="edit-profile-country-wrapper">
 			<label for="edit-profile-country">Country: <span class="form-required" title="This field is required.">*</span></label>
 			<input type="text" maxlength="255" name="profile_country" id="edit-profile-country" size="60" value="" class="form-text required" />
		</div>

		<div class="form-item" id="edit-profile-phone-wrapper">
 			<label for="edit-profile-phone">Phone: <span class="form-required" title="This field is required.">*</span></label>
 			<input type="text" maxlength="255" name="profile_phone" id="edit-profile-phone" size="60" value="" class="form-text required" />
		</div>
		
		<div class="form-item" id="edit-profile-birthday-wrapper">
 			<label for="edit-profile-birthday">Birthday: </label>
 			<div class="container-inline"><div class="form-item" id="edit-profile-birthday-month-wrapper">
 			<select name="profile_birthday[month]" class="form-select" id="edit-profile-birthday-month" >
 				<option value="1">Jan</option>
 				<option value="2">Feb</option>
 				<option value="3">Mar</option><option value="4">Apr</option><option value="5">May</option><option value="6" selected="selected">Jun</option><option value="7">Jul</option><option value="8">Aug</option><option value="9">Sep</option><option value="10">Oct</option><option value="11">Nov</option><option value="12">Dec</option></select>

</div>
<div class="form-item" id="edit-profile-birthday-day-wrapper">
 <select name="profile_birthday[day]" class="form-select" id="edit-profile-birthday-day" ><option value="1">1</option><option value="2">2</option><option value="3">3</option><option value="4">4</option><option value="5">5</option><option value="6">6</option><option value="7">7</option><option value="8">8</option><option value="9">9</option><option value="10">10</option><option value="11">11</option><option value="12">12</option><option value="13">13</option><option value="14" selected="selected">14</option><option value="15">15</option><option value="16">16</option><option value="17">17</option><option value="18">18</option><option value="19">19</option><option value="20">20</option><option value="21">21</option><option value="22">22</option><option value="23">23</option><option value="24">24</option><option value="25">25</option><option value="26">26</option><option value="27">27</option><option value="28">28</option><option value="29">29</option><option value="30">30</option><option value="31">31</option></select>

</div>
<div class="form-item" id="edit-profile-birthday-year-wrapper">
 <select name="profile_birthday[year]" class="form-select" id="edit-profile-birthday-year" ><option value="1900">1900</option><option value="1901">1901</option><option value="1902">1902</option><option value="1903">1903</option><option value="1904">1904</option><option value="1905">1905</option><option value="1906">1906</option><option value="1907">1907</option><option value="1908">1908</option><option value="1909">1909</option><option value="1910">1910</option><option value="1911">1911</option><option value="1912">1912</option><option value="1913">1913</option><option value="1914">1914</option><option value="1915">1915</option><option value="1916">1916</option><option value="1917">1917</option><option value="1918">1918</option><option value="1919">1919</option><option value="1920">1920</option><option value="1921">1921</option><option value="1922">1922</option><option value="1923">1923</option><option value="1924">1924</option><option value="1925">1925</option><option value="1926">1926</option><option value="1927">1927</option><option value="1928">1928</option><option value="1929">1929</option><option value="1930">1930</option><option value="1931">1931</option><option value="1932">1932</option><option value="1933">1933</option><option value="1934">1934</option><option value="1935">1935</option><option value="1936">1936</option><option value="1937">1937</option><option value="1938">1938</option><option value="1939">1939</option><option value="1940">1940</option><option value="1941">1941</option><option value="1942">1942</option><option value="1943">1943</option><option value="1944">1944</option><option value="1945">1945</option><option value="1946">1946</option><option value="1947">1947</option><option value="1948">1948</option><option value="1949">1949</option><option value="1950">1950</option><option value="1951">1951</option><option value="1952">1952</option><option value="1953">1953</option><option value="1954">1954</option><option value="1955">1955</option><option value="1956">1956</option><option value="1957">1957</option><option value="1958">1958</option><option value="1959">1959</option><option value="1960">1960</option><option value="1961">1961</option><option value="1962">1962</option><option value="1963">1963</option><option value="1964">1964</option><option value="1965">1965</option><option value="1966">1966</option><option value="1967">1967</option><option value="1968">1968</option><option value="1969">1969</option><option value="1970">1970</option><option value="1971">1971</option><option value="1972">1972</option><option value="1973">1973</option><option value="1974">1974</option><option value="1975">1975</option><option value="1976">1976</option><option value="1977">1977</option><option value="1978">1978</option><option value="1979">1979</option><option value="1980">1980</option><option value="1981">1981</option><option value="1982">1982</option><option value="1983">1983</option><option value="1984">1984</option><option value="1985">1985</option><option value="1986">1986</option><option value="1987">1987</option><option value="1988">1988</option><option value="1989">1989</option><option value="1990">1990</option><option value="1991">1991</option><option value="1992">1992</option><option value="1993">1993</option><option value="1994">1994</option><option value="1995">1995</option><option value="1996">1996</option><option value="1997">1997</option><option value="1998">1998</option><option value="1999">1999</option><option value="2000">2000</option><option value="2001">2001</option><option value="2002">2002</option><option value="2003">2003</option><option value="2004">2004</option><option value="2005">2005</option><option value="2006">2006</option><option value="2007">2007</option><option value="2008">2008</option><option value="2009">2009</option><option value="2010" selected="selected">2010</option><option value="2011">2011</option><option value="2012">2012</option><option value="2013">2013</option><option value="2014">2014</option><option value="2015">2015</option><option value="2016">2016</option><option value="2017">2017</option><option value="2018">2018</option><option value="2019">2019</option><option value="2020">2020</option><option value="2021">2021</option><option value="2022">2022</option><option value="2023">2023</option><option value="2024">2024</option><option value="2025">2025</option><option value="2026">2026</option><option value="2027">2027</option><option value="2028">2028</option><option value="2029">2029</option><option value="2030">2030</option><option value="2031">2031</option><option value="2032">2032</option><option value="2033">2033</option><option value="2034">2034</option><option value="2035">2035</option><option value="2036">2036</option><option value="2037">2037</option><option value="2038">2038</option><option value="2039">2039</option><option value="2040">2040</option><option value="2041">2041</option><option value="2042">2042</option><option value="2043">2043</option><option value="2044">2044</option><option value="2045">2045</option><option value="2046">2046</option><option value="2047">2047</option><option value="2048">2048</option><option value="2049">2049</option><option value="2050">2050</option></select>

</div>
</div>
</div>
<div class="form-item">
 <label>Gender: <span class="form-required" title="This field is required.">*</span></label>
 <div class="form-radios"><div class="form-item" id="edit-profile-gender-0-wrapper">
 <label class="option" for="edit-profile-gender-0"><input type="radio" id="edit-profile-gender-0" name="profile_gender" value="0"   class="form-radio" /> Male</label>
</div>
<div class="form-item" id="edit-profile-gender-1-wrapper">
 <label class="option" for="edit-profile-gender-1"><input type="radio" id="edit-profile-gender-1" name="profile_gender" value="1"   class="form-radio" /> Female</label>

</div>
</div>
</div>
<div class="form-item" id="edit-profile-usedinmarketing-wrapper">
 <label class="option" for="edit-profile-usedinmarketing"><input type="checkbox" name="profile_usedinmarketing" id="edit-profile-usedinmarketing" value="1"   class="form-checkbox" /> My information can be used in marketing</label>
</div>
<div class="form-item" id="edit-profile-sendtoinbox-wrapper">
 <label class="option" for="edit-profile-sendtoinbox"><input type="checkbox" name="profile_sendtoinbox" id="edit-profile-sendtoinbox" value="1"   class="form-checkbox" /> Send private messages to my inbox</label>
</div>
</fieldset>
<fieldset><legend>Terms of Use</legend><div id="terms-of-use" class="content clear-block"><p>This is term and condition of the ESS Registration</p>

</div><div class="form-item" id="edit-terms-of-use-wrapper">
 <label class="option" for="edit-terms-of-use"><input type="checkbox" name="terms_of_use" id="edit-terms-of-use" value="1"   class="form-checkbox required" /> Type here something like "I agree with these terms." or "I CERTIFY THAT I AM OVER THE AGE OF 18 YEARS OLD.", without quotes. You&nbsp;<span class="form-required" title="This field is required">*</span></label>
</div>
</fieldset>
<fieldset class="captcha"><legend>CAPTCHA</legend><div class="description">This question is for testing whether you are a human visitor and to prevent automated spam submissions.</div><input type="hidden" name="captcha_sid" id="edit-captcha-sid" value="154"  />
<img src="/?q=image_captcha/154/1276515812" alt="Image CAPTCHA" title="Image CAPTCHA" /><div class="form-item" id="edit-captcha-response-wrapper">
 <label for="edit-captcha-response">What code is in the image?: <span class="form-required" title="This field is required.">*</span></label>
 <input type="text" maxlength="128" name="captcha_response" id="edit-captcha-response" size="15" value="" class="form-text required" />

 <div class="description">Enter the characters shown in the image.</div>
</div>
</fieldset>
<input type="submit" name="op" id="edit-submit" value="Create new account"  class="form-submit" />

</div></form-->


<?php //print $taTermsOfUse; ?>
<?php //print $taTermsOfUse1; ?>


<?php //print $txtFirstName; ?>
<?php //print $txtLastName; ?>

<?php //print $txtUserName; ?>
<?php //print $txtUserEmail; ?>
<?php //print $txtSecondaryEmail; ?>
 
<?php //print $taAddress; ?>
<?php //print $txtZip; ?>
<?php //print $txtCity; ?>
<?php //print $txtCountry; ?>

<?php //print $txtPhone; ?>
<?php //print $txtBirthday; ?>
<?php //print $txtGender; ?>
<?php //print $chkUsedInMarketing; ?>
<?php //print $chkSendToInbox; ?>

<?php //print $wdgtCaptcha; ?>


<?php //print $btnSubmit; ?>
			
	

