<?php
if (isset($_POST['product_id'])) {
    $conn= new mysqli('localhost', 'root', '', 'productdb');
    
    $id =(int) $_POST['product_id'];
    $stmt = $conn->prepare("SELECT * FROM products WHERE id = ?");
    $stmt->bind_param("i", $id);
    $stmt->execute();

    $result= $stmt->get_result();
    if ($row = $result->fetch_assoc()) {
        echo "<h3>" . htmlspecialchars($row['name']) . "</h3>";
        echo "<p><strong>Price:</.strong> $" . htmlspecialchars($row['price']) . "</p>";
        echo "<p><strong>Description:</strong> " . htmlspecialchars($row['description']) . "</p>";
    }else {
        echo "<p>No product found.</p>";
    }  
    
    $stmt->close();
    $conn->close();
}
?>