<!DOCTYPE html>
<html>
<body>
    <h2>PHP Array</h2>    
    <ul> <strong>Indexed Array</strong>
        <?php
            // indexed array
            $arr1= [2,4,6,10];
            // displaying the array
            foreach ($arr1 as $value) {
                echo "<li>$value </li>";
            }
            
        ?>
    </ul>   
    <ul><strong>Associative Array</strong>
        <?php 
            // associative array
            $arr2= ['name' => 'joy', 'age'=> 22, 'gender' => 'male', 'hobby' => 'sports'];

            foreach ($arr2 as $key => $value) {
                echo "<li>$key : $value </li>";
            }
        ?>
    </ul>

</body>
</html>