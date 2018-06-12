<?php

define("STYLE_LOCATION", "../assets/styles.css");
define("LOGO_TEXT_ONLY_LOCATION", "../assets/logos/logo_text_only.png");
define("SITE_BG_COLOUR", "ECEEF0"); // default is ECEEF0, or L I G H T grey.
define("SITE_HEADER_COLOUR", "808080"); // default is 808080, or grey.
define("SITE_NAME", "localhost");

function page_container($page_title, $page_author)
{
	echo "<html><head><title>" . $page_title . " - " . SITE_NAME . "</title><meta name='author' content='" . $page_author . "'><link rel='stylesheet' href='" . STYLE_LOCATION . "'></head></html>";
}

function page_header()
{
	$header2_enabled = false;
	$header2_text    = "hello my dudes";

	$header = "<html>
				<header class='header'>
					&emsp;<a href='../../index.php'><img src='" . LOGO_TEXT_ONLY_LOCATION . "' alt='logo'></a>
				</header>
			   </html>";

	echo $header;

	if ($header2_enabled == true)
	{
		echo "<div id='header_extra'>" . $header2_text . "</div>";
	}
}

?>