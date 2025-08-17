// M M 1 queuing system

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double lambda, mu;

    // Input values
    cout << "Enter Arrival Rate : ";
    cin >> lambda;

    cout << "Enter Service Rate : ";
    cin >> mu;

    // Check stability condition
    if (lambda >= mu) {
        cout << "System is unstable. Arrival rate must be less than service rate (λ < μ)." << endl;
        return 1;
    }

    // Calculating traffic intensity
    double rho = lambda / mu;

    // Calculating M/M/1 queue measures
    double L = lambda / (mu - lambda); // Average number in system
    double Lq = (lambda * lambda) / (mu * (mu - lambda)); // Average number in queue
    double W = 1 / (mu - lambda); // Average time in system
    double Wq = lambda / (mu * (mu - lambda)); // Average time in queue

    // Displaying results
    cout << fixed << setprecision(3);
    cout << "\nM/M/1 Queue Performance Measures:\n";
    cout << "Traffic Intensity (ρ): " << rho << endl;
    cout << "Average number in system (L): " << L << endl;
    cout << "Average number in queue (Lq): " << Lq << endl;
    cout << "Average time in system (W): " << W << endl;
    cout << "Average time in queue (Wq): " << Wq << endl;

    return 0;
}
