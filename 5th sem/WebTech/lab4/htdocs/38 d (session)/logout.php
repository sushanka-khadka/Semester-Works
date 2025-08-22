<?php
session_start();
session_unset(); // Unset all session variables
session_destroy(); // Destroy the session

// delete cookie
setcookie('remember_username', '', time() -3600, '/'); // Delete the cookie by setting its expiration time in the past

header("Location: login.php"); // Redirect to the login page
exit; // Ensure no further code is executed
?>