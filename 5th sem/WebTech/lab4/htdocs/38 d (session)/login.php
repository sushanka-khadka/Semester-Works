<?php 
session_start();

// Dummy ceredentials
$correct_username = "admin";
$correct_password = "password";

// auto-login using cookie
if (!isset($_SESSION['username']) && isset($_SESSION['remember_username'])) {
    $_SESSION['username'] = $_COOKIE['remember_username'];
    header("Location: welcome.php");
    exit;    
}

$error = '';
// Check if the form is submitted
if( $_SERVER['REQUEST_METHOD'] == 'POST') {
    $username= $_POST['username'] ?? '';
    $password = $_POST['password'] ?? '';
    $remember = $_POST['remember'] ?? false;
    
    // Validate credentials
    if ($username === $correct_username && $password === $correct_password) {
        $_SESSION['username'] = $username;

        if ($remember) {
            // Set a cookie for auto-login
            setcookie('remember_username', $username, time() + (86400 *7), '/'); // set cookie for 7 days            
        }else {
            // Clear the cookie if "Remember Me" is not checked
            setcookie('remember_username', '', time() - 3600, '/');
        }

        header("Location: welcome.php");
        exit;        
    }else {
        $error = "Invalid username or password.";
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>login</title>
    <style>
        .error {color: red;}
        form { max-width: 500px; margin:auto; justify-items: center; }
        input {             
            margin-bottom: 10px;            
            padding: 8px; 
        }        
    </style>
</head>
<body>
    <h2 style='text-align: center;'>Login Page</h2>
    <form method='post' action =''>
        <label>Username: 
            <input type='text' name='username' required>
        </label></br>
        <label>Password:
            <input type='password' name='password' required>
        </label><br>

        <label>
            <input type='checkbox' name ='remember'>Remember Me
        </label><br>
        
        <input type='submit' value='Login'>
        <p class='error'><?php echo $error; ?></p>
    </form>
</body>
</html>