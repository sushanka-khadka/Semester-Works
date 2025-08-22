<?php
 include 'config.php'; 

$id= $_GET['id'];
$stmt= $conn->prepare("DELETE FROM users WHERE id = ?");
$stmt->bind_param('i', $id); // 'i' indicates that the parameter is an integer
$stmt->execute();

header("Location: read.php"); // Redirect to the user list after deletion
exit; // Ensure no further code is executed after the redirect

?>