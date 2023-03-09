<?php

$json = file_get_contents('php://input');
$obj = json_decode($json);
$temp = $obj->{'temp'}; 
$humid = $obj->{'humid'};
$device_id = $obj->{'deviceID'};


$dbserver = "localhost";			// Database server
$dbname= 'im';
$dbuser = 'im';
$dbpass= 'ab';

date_default_timezone_set('Asia/Bangkok');
$dateTime = new DateTime();
$now = $dateTime->format('Y-m-d H:i:s');


$conn = new mysqli($dbserver, $dbuser, $dbpass, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 
$conn->query("set NAMES utf8");

$sql = "INSERT INTO testiot (device_id, temp, humid, dt)" .
 " VALUES ('$device_id','$temp', '$humid', '$now')";

if ($conn->query($sql) === TRUE) {
    echo "Record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>