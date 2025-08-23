<?php
$host= 'localhost';
$username = 'root';
$password = '';
$dbname= 'crud_php';

// create connnection
$conn= new mysqli($host, $username, $password, $dbname);

// check for connection
if ($conn->connect_error) {
    die('Connection failed: ' . $conn->connect_error)    ;
}
?>