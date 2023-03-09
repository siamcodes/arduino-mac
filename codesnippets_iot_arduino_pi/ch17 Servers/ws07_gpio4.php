<h2>Test GPIO 4 ON/Off</h2>
<?php
	system ("gpio -g mode 4 out") ;

	$mode = $_GET['mode'];
	if ($mode == 1) {
		system ("gpio -g write 4 1") ;
		echo "Now: ON";
		echo "<hr><a href='./gpio4.php?mode=0'>Turn OFF</a>";
	} else {
		system ("gpio -g write 4 0") ;
		echo "Now: OFF";
		echo "<hr><a href='./gpio4.php?mode=1'>Turn ON</a>";
	}
?> 

