// point estimation

#include <iostream>
#include <vector>
#include <numeric>  // for accumulate
#include <iomanip>  // for setprecision

using namespace std;

int main() {
    int n;
    double population_mean;

    // Input population mean
    cout << "Enter the population mean: ";
    cin >> population_mean;

    // Input sample size
    cout << "Enter the number of samples: ";
    cin >> n;

    vector<double> sample(n);

    // Input sample data
    cout << "Enter the sample data:\n";
    for (int i = 0; i < n; ++i) {
        cin >> sample[i];
    }

    // Calculate sample mean
    double sum = accumulate(sample.begin(), sample.end(), 0.0);
    double sample_mean = sum / n;

    // Calculate bias
    double bias = sample_mean - population_mean;

    // Output results
    cout << fixed << setprecision(4);
    cout << "\nSample Mean (Point Estimate): " << sample_mean << endl;
    cout << "Bias = Sample Mean - Population Mean: " << bias << endl;

    return 0;
}
