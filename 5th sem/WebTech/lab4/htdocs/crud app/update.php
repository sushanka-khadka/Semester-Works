<!-- edit user info -->
 <?php include 'config.php'; ?>
<!DOCTYPE html>
<html>
<head><title>Update User</title></head>
<body>
    <h2>Update User</h2>

<?php
$id= $_GET['id'];
$result = $conn->query("SELECT * FROM users WHERE id = $id");
$row = $result->fetch_assoc();
?>

<form method='post'>
    Name: <input type='text' name='name' value='<?= $row['name'] ?>' required><br>
    Email: <input type='text' name='email' value='<?= $row['email'] ?>' required><br><br>
    <button type='submit' name='update'>Update User</button>
</form>
<a href='read.php'>Back to List</a>

<?php
if (isset($_POST['update'])) {
    $name= $_POST['name'];
    $email= $_POST['email'];
    $stmt = $conn->prepare("UPDATE users SET name = ?, email = ? WHERE id = ?");
    $stmt->bind_param('ssi', $name, $email, $id); // 'ssi' indicates two strings and one integer

    if ($stmt->execute()) 
        echo "<p>User updated successfully!</p>";
    else 
        echo "<p>Error updating user: " . $stmt->error . "</p>";
}
?>
</body>
</html>