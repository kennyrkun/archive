<?php

$snow_script_include "<script src='snowstorm-min.js'></script>";
$snow_script_settings = "<script>snowStorm.followMouse = false;snowStorm.flakesMaxActive = 1000;snowStorm.snowStick = false;</script>";

$timestamp = strtotime($datedata);

$month = date('F', $timestamp);

if ($month == "December") {
	echo $snow_script_include
}

