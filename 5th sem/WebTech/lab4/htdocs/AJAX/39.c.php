<?php
if ($_SERVER['REQUEST_METHOD'] === "POST") {
    $name = htmlspecialchars($_POST['name']);
    echo "Hello, " . $name . "! This is a response from the server.";
}else
    echo "No name received via POST.";

?>