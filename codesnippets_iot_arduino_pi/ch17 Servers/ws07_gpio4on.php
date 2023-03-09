<h2>Test GPIO 4 ON</h2>
<?php
	system ("gpio -g mode 4 out") ;
	system ("gpio -g write 4 1") ;
?> 
