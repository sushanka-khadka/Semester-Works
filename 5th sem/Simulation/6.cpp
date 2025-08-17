//interval/ confidence interval estimation for a sample of data with given population mean.

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <numeric> // for accumulate

using namespace std;

// Function to calculate standard deviation
double calculate_std_dev(const vector<double>& data, double mean) {
    double sum = 0.0;
    for (double x : data) {
        sum += (x - mean) * (x - mean);
    }
    return sqrt(sum / (data.size() - 1));  // sample standard deviation
}

int main() {
    int n;
    double population_mean;
    double confidence_level;

    cout << "Enter the number of samples: ";
    cin >> n;

    vector<double> sample(n);

    cout << "Enter the sample data:\n";
    for (int i = 0; i < n; ++i) {
        cin >> sample[i];
    }

    cout << "Enter population mean (if known, else enter 0): ";
    cin >> population_mean;

    cout << "Enter confidence level (e.g. 0.95 for 95%): ";
    cin >> confidence_level;

    // Z-scores for common confidence levels (you can extend this)
    double z = 0;
    if (confidence_level == 0.90) z = 1.645;
    else if (confidence_level == 0.95) z = 1.960;
    else if (confidence_level == 0.99) z = 2.576;
    else {
        cout << "Unsupported confidence level. Use 0.90, 0.95, or 0.99.\n";
        return 1;
    }

    // Calculate sample mean
    double sum = accumulate(sample.begin(), sample.end(), 0.0);
    double sample_mean = sum / n;

    // Calculate sample standard deviation
    double std_dev = calculate_std_dev(sample, sample_mean);

    // Calculate margin of error
    double margin = z * (std_dev / sqrt(n));

    // Confidence interval
    double lower = sample_mean - margin;
    double upper = sample_mean + margin;

    // Output
    cout << fixed << setprecision(4);
    cout << "\nSample Mean: " << sample_mean << endl;
    cout << "Sample Standard Deviation: " << std_dev << endl;
    cout << confidence_level * 100 << "% Confidence Interval: ["
         << lower << ", " << upper << "]\n";

    return 0;
}
