<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $name = htmlspecialchars($_POST['name']);
    echo "Hello, " . $name . "! This response is from PHP via jQuery AJAX.";
} else 
    echo "No name received.";
?>