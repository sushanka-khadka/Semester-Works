<!--  insert new user -->
<?php include 'config.php'?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Create User</title>
</head>
<body>
    <h2>Create New User</h2>
    <form method='post'>
        Name: <input type='text' name='name' required><br>
        Email: <input type='email' name='email' required><br>
        <button type='submit' name ='submit'>Create User</button>
    </form>
    <a href = 'read.php'>View Users</a>
    
<?php
if (isset($_POST['submit'])) {
    $name = $_POST['name'];
    $email = $_POST['email'];

    // $sql = "INSERT INTO users (name, email) VALUES ('$name', '$email')"; plain sql vulnerable to SQL injection
    // $result = mysqli_query($conn, $sql);

    /* Prepared statement to prevent SQL injection         
    Sends the query to MySQL for pre-compilation (without values).
    Creates a statement object ($stmt) that can later be safely bound to variables.
    Protects against SQL injection because data is sent separately from the query.
    */

    $stmt = $conn->prepare("INSERT INTO users (name, email) values (?,?)");  
    $stmt->bind_param('ss', $name, $email); // Binds the variables to the prepared statement as parameters. 'ss' indicates that both parameters are strings.

    if ($stmt->execute()) 
        echo "<p>User created successfully!</p>";
    else
        echo "<p>Error creating user: " . $stmt->error . "</p>";
}   
?>
</body>
</html>