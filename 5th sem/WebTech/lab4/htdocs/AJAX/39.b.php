<?php
if (isset($_GET['name'])) {
    $name = htmlspecialchars($_GET['name']);    // sanitize input
    echo "Helllo, " . $name . "! This response if from PHP.";
} else {
    echo "No name received.";
}
?>