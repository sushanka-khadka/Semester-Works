<!DOCTYPE html>
<html>
<head>
    <title>Order Form</title>
    <script>
        function validateCustomerName() {
            const name = document.getElementById("customer").value.trim();
            if (name === ''){
                alert ("Please enter a customer name.");
                return false;
            }
            return true;
        }

        function validateQuuantity() {
            const quantity= document.getElementById("quantity").value;
            if (isNaN(quantity) || quantity <= 0){
                alert ("Quantity must be a +ve number.");
                return false;
            }
            return true;
        }

        function validateForm() {
            return validateCustomerName() && validateQuuantity();
        }
    </script>
</head>
<body>
    <h3>Product Order Form</h3>
    <form method ='post' action ='' onsubmit='return validateForm()'>
        Customer Name: 
        <input type='text' id='customer' name='customer' onblur='validateCustomerName()'><br><br>
        Product: <select name='product'>
            <option value=''>Select a product</option>
            <option value='laptop'>Laptop</option>
            <option value='phone'>Phone</option>
            <option value='tablet'>Tablet</option>
            </select><br><br>

            Quantity:
            <input type='number' id='quantity' name='quantity' min='1' onblur='validateQuuantity()'><br><br>
        <input type='submit' value='Calculate Total'>
    </form>
</body>
</html>

<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $customer = htmlspecialchars($_POST['customer']);
    $product = $_POST['product'];
    $quantity = (int)$_POST['quantity'];

    // prices 
    $prices =[
        'laptop' => 1000,
        'phone' => 500,
        'tablet' => 300
    ];

    $unit_price = $prices[$product];
    $total = $unit_price * $quantity;

    echo "<h2>Order Summary</h2>
        Customer Name: $customer<br>
        Product: $product<br>
        Quantity: $quantity<br>
        Unit Price: $$unit_price<br>
        <strong>Total Price: $$total</strong>";
}
?>

