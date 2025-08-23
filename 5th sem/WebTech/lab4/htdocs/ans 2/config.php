 <!-- database connection -->

<?php
$host = 'localhost';
$user = 'root';
$password = '';
$database = 'ans_2_db';

$conn = new mysqli($host, $user, $password, $database);

if($conn->connect_error) {
    dir("Connection failed: " . $conn->connect_error);
}
?>