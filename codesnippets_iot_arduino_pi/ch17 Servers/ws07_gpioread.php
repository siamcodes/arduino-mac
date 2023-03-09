<h2>Test GPIO Read</h2>
<?php
	system("gpio -g mode 17 in") ;
	exec("gpio -g read 17", $gpio17);
	// print_r($gpio17);

	echo "GPIO17 = " .  $gpio17[0] ;
?> 
