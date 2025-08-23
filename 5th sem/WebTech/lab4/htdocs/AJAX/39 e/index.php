<!-- html + ajax -->
<!DOCTYPE html>
<html>
<head>
    <title>AJAX Dropdown with PHP and MySQL</title>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script>
        function fetchDetails(id) {
            $.ajax({
                url: 'get_product.php',
                type: 'POST',
                data: {product_id: id},
                success: function(response) {
                    $('#productDetails').html(response);
                }
            });
        }
    </script>
</head>
<body>
    <h3>Select a Product</h3>
    <select onchange='fetchDetails(this.value)'>
        <option value="">-- Select product --</option>
        <?php
            // Database connection
            $conn = new mysqli('localhost', 'root', '', 'productdb');
            
            // fetch product list
            $result= $conn->query("SELECT id, name FROM products");
            while ($row = $result->fetch_assoc()) {
                echo "<option value = '{$row["id"]}'>{$row['name']}</option>";
            }
        ?>
    </select>
    <div id="productDetails" style="margin-top:20px;"></div>
</body>
</html>


        
