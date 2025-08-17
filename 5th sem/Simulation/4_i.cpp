// // auto-correlation test for independence of random nunbers 
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to compute mean of a sequence
double computeMean(const vector<double>& data) {
    double sum = 0.0;
    for (double val : data) sum += val;
    return sum / data.size();
}

// Function to perform autocorrelation test
double autocorrelationTest(const vector<double>& data, int lag) {
    int n = data.size();
    double mean = computeMean(data);

    double numerator = 0.0;
    double denominator = 0.0;

    for (int i = 0; i < n - lag; ++i) {
        numerator += (data[i] - mean) * (data[i + lag] - mean);
    }

    for (int i = 0; i < n; ++i) {
        denominator += (data[i] - mean) * (data[i] - mean);
    }

    return numerator / denominator;
}

int main() {
    int n, lag;
    cout<<"----- Auto-correlation test -----\n";
    cout << "Enter number of random numbers to generate: ";
    cin >> n;

    cout << "Enter lag value: ";
    cin >> lag;

    if (lag >= n || lag <= 0) {
        cout << "Invalid lag. It must be > 0 and < n.\n";
        return 1;
    }

    vector<double> randomNumbers(n);
    srand(time(0));

    cout << "Generated Random Numbers:\n";
    for (int i = 0; i < n; ++i) {
        randomNumbers[i] = (double)rand() / RAND_MAX;
        cout << fixed << setprecision(4) << randomNumbers[i] << " ";
    }
    cout << endl;

    double r_d = autocorrelationTest(randomNumbers, lag);

    cout << "\nAutocorrelation Coefficient (lag " << lag << "): " << fixed << setprecision(5) << r_d << endl;

    if (abs(r_d) < 0.1)
        cout << "=> Likely independent (good randomness)\n";
    else
        cout << "=> Possible correlation (poor randomness)\n";

    return 0;
}