<html>
<body>

<form action="38.b.php" method= "POST">
    Name: <input type="text" name="name"><br>
    Age: <input type="number" name="age"><br>
    <input type="submit">
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST['name'];    
    $name = htmlspecialchars($name);  // Converts special characters to HTML entities to prevent XSS attacks.
    $age = $_POST['age'];
    
    echo "Welcome ". $name. "<br>";

    if(! empty($age)) {
        echo "Your age is: " . $age . "<br>";
        if ($age % 2 == 0) {
            echo "Your age is even.<br> Multiplication table of your age.:<br>";
            foreach (range(1, 10) as $i){
                echo "{$age} * {$i} = " . $age * $i . "<br>";
            }
        } else {
            // age is odd -> display vowels and consonants counts
            echo "Your age is odd.<br>";
            $vowels = preg_match_all('/[aeiou]/i', $name);
            echo "No. of vowels in your name: " . $vowels . "<br>" .
            "No of consonants in your name: " . (strlen($name) - $vowels) . "<br>";                     
        }
    } else {
        echo "Age is required!.<br>";
    }
}
?>

</body>
</html>
