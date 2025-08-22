<?php
class Car {
    public $brand;
    public $color;

    // Constructor to initialize the properties
    public function __construct($brand, $color) {
        $this->brand = $brand;
        $this->color = $color;
    }

    // method to display car details
    public function displayInfo() {
        echo "Brand: " . $this->brand . "<br>";
        echo "Color: " . $this->color . "<br><br>";
    }
}


// Create an instance of the Car class
$car1 = new Car("Toyata", "Red");
$car2 = new Car("Honda", "Blue");

// call methods on the obhects
echo "<h3>Car 1 Details:</h3>";
$car1->displayInfo();
echo "<h3>Car 2 Details:</h3>";
$car2->displayInfo();

?>