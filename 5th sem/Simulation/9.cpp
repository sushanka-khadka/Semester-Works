// area under curve using monte carlo simulation 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Function to define the curve
double f(double x) {
    return x * x;  // You can change this function
}

int main() {
    int num_points;
    double a = 0.0, b = 1.0;        // Interval [a, b]
    double f_max = 1.0;            // Max value of f(x) on [0,1] for x^2 is 1.0
	
	cout<<"--- Area Under Curve (Monte Carlo) ----\n";
    cout << "Enter number of random points to generate: ";
    cin >> num_points;

    srand(time(0));  // Seed RNG

    int points_below_curve = 0;

    for (int i = 0; i < num_points; ++i) {
        double x = a + (double)rand() / RAND_MAX * (b - a);
        double y = (double)rand() / RAND_MAX * f_max;

        if (y <= f(x)) {
            points_below_curve++;
        }
    }

    double area_estimate = ((double)points_below_curve / num_points) * (b - a) * f_max;
	cout<<"\nPoints below curve: "<<points_below_curve;
    cout << "\nEstimated area under the curve y = x^2 from " << a << " to " << b << " is: " << area_estimate << endl;

    return 0;
}
