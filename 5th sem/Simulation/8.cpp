#include <iostream>
#include <cstdlib>  // for rand() and RAND_MAX
#include <ctime>    // for time()

using namespace std;

int main() {
    int num_points;
    int inside_circle = 0;

    cout<<"------- Monte Carlo Simulation -------\n";
	cout << "Enter number of points to generate: ";
    cin >> num_points;

    // Seed the random number generator
    srand(time(0));

    for (int i = 0; i < num_points; ++i) {
        // Generate random (x, y) in [0, 1]
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
		
        // Check if the point is inside the quarter circle
        if (x * x + y * y <= 1.0) {
            inside_circle++;
        }
    }

    // Estimate PI
    double pi_estimate = 4.0 * inside_circle / num_points;

    cout<<"\nNo of points inside circle: "<<inside_circle<<endl;
	cout << "Estimated value of PI = " << pi_estimate << endl;

    return 0;
}
