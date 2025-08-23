<?php
require 'db.php';
if (isset($_POST['query'])) {
    $search = $conn->real_escape_string($_POST['query']);

    $sql ="SELECT * FROM users WHERE name LIKE '%$search%' LIMIT 10";
    $result = $conn->query($sql);
    
    if ($result->num_rows > 0){
        echo '<ul>';
        while ($row = $result->fetch_assoc()) {
            echo '<li>' .htmlspecialchars($row['name']) . '</li>';            
        }
        echo "</ul>";        
    }else
        echo '<p>No results found</p>';
}
?>