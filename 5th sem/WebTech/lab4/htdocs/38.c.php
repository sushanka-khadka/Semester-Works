<?php
$name = $email = $username = $password = $confirm_password = "";
$nameErr = $emailErr = $usernameErr = $passwordErr = $confirm_passwordErr = "";
$successMsg = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $isValid = true; // Flag to check if all fields are valid  
    
    // FULL NAME
    if (empty($_POST['name'])){
        $nameErr = "Full Name is required";
        $isValid = false;
    }else
        $name = htmlspecialchars(trim($_POST['name'])); // Converts special characters to HTML entities to prevent XSS attacks.']))       

    // email
        if (empty($_POST['email'])){
        $emailErr = "Email is required";
        $isValid = false;
    }elseif (!filter_var($_POST['email'], FILTER_VALIDATE_EMAIL)) {
        $$emailErr = "Invalid email format";
        $isValid = false;
    } else 
        $email = htmlspecialchars(trim($_POST['email'])); 
    
    // username (regex)
    if (empty($_POST['username'])){
        $usernameErr = "Username is required";
        $isValid = false;
    } elseif (!preg_match('/^[a-zA-Z0-9_]+$/', $_POST['username'])) {
        $usernameErr= 'Username can only contain letters, numbers, and underscores';
        $isValid = false;
    }else
        $username = htmlspecialchars(trim($_POST['username'])); // Converts special characters to HTML entities to prevent XSS attacks.']))       

    // password
    if(empty($_POST['password'])) {
        $passwordErr= "Password is required";
        $isValid = false;
    }elseif (strlen($_POST['password'] < 8)) {
        $passwordErr = "Password must be at least 8 characters long";
        $isValid = false;
    }else
        $password = htmlspecialchars(trim($_POST['password'])); 

    // confirm password
    if(empty($_POST['confirm_password'])) {
        $confirm_passwordErr= 'Please confirm your password';
        $isValid = false;
    }elseif ($_POST['confirm_password'] !== $_POST['password']) {
        $confirm_passwordErr = 'Passwords do not match';
        $isValid = false;
    }else
        $confirm_password = htmlspecialchars(trim($_POST['confirm_password']));

    // If all fields are valid, process the registration
    if($isValid) {
        $successMsg = "Registration successful! Welcome, " . $name . ".<br>";
        // here data can be inserted into a database or processed further        
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registration Form</title>
    <style>
        .error {color: red;}
        .success {color: green;}
        form {max-width: 400px; margin:auto;}
        form {max-width: 400px; margin:auto}
        input[type="text"], input[type="email"], input[type="password"]
         {
            width: 100px; padding: 8px; margin: 6px 0;
         }
         input[type="submit"] {             
            width: 100px; padding: 8px; margin: 6px 0;
            background-color: #4CAF50; color: white; border: none;
            cursor: pointer;
         }
    </style>
</head>
<body>
    <h2 style='text-align:center;'>User Registration Form</h2>
    <p class='success' style='text-align: center;'> <?php echo $successMsg ?> </p>
    <form method='post' action='<?php echo htmlspecialchars($_SERVER['PHP_SELF']); ?>'>
        <label>Full Name:
            <input type="text" name="name" value= '<?php echo $name; ?>'>
        </label>
        <span class='error'><?php echo $nameErr; ?></span><br>
        
        <label>Email:
            <input type="email" name="email" value= '<?php echo $email; ?>'>
        </label>
        <span class='error'><?php echo $emailErr; ?></span><br>

        <label>Username:
            <input type="text" name="username" value= '<?php echo $username; ?>'>
        </label>
        <span class='error'><?php echo $usernameErr; ?></span><br>

        <label>Password:
            <input type="password" name="password">
        </label>
        <span class='error'><?php echo $passwordErr; ?></span><br>

        <label>Confirm Password:
            <input type="password" name="confirm_password">
        </label>
        <span class='error'><?php echo $confirm_passwordErr; ?></span><br>

        <input type="submit" value="Register">
    </form>
    
</body>
</html>

