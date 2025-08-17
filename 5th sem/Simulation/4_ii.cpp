#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

// Classify digit group
string classifyGroup(const string& group) {
    map<char, int> freq;
    for (char c : group) freq[c]++;
    
    vector<int> counts;
    for (auto& p : freq) counts.push_back(p.second);
    
    sort(counts.rbegin(), counts.rend());

    if (counts[0] == 4) return "Four of a kind";
    if (counts[0] == 3 && counts[1] == 1) return "Three of a kind";
    if (counts[0] == 2 && counts[1] == 2) return "Two pairs";
    if (counts[0] == 2) return "One pair";
    return "All different";
}

int main() {
    int totalDigits, groupSize;
    cout<<"----------- Poker Test (Independence Test) -----------\n";
	cout << "Enter total number of random digits to generate (e.g., 20000): ";
    cin >> totalDigits;

    cout << "Enter size of each group (e.g., 4): ";
    cin >> groupSize;

    if (totalDigits % groupSize != 0) {
        cout << "Error: Total digits must be divisible by group size.\n";
        return 1;
    }

    int numGroups = totalDigits / groupSize;
    map<string, int> patternFreq;

    srand(time(0));

    // Generate and classify groups
    for (int i = 0; i < numGroups; ++i) {
        string group = "";
        for (int j = 0; j < groupSize; ++j) {
            group += '0' + rand() % 10;
        }
        string pattern = classifyGroup(group);
        patternFreq[pattern]++;
    }

    // Show observed frequencies
    cout << "\nObserved Frequencies:\n";
    for (auto& p : patternFreq) {
        cout << setw(20) << left << p.first << ": " << p.second << "\n";
    }

    // Theoretical probabilities for 4-digit Poker test (base-10):
    // Based on known probabilities from statistical tables
    map<string, double> expectedProbs = {
        {"All different", 0.504},
        {"One pair",      0.432},
        {"Two pairs",     0.027},
        {"Three of a kind", 0.036},
        {"Four of a kind",  0.001}
    };

    // Chi-square test
    double chi_square = 0.0;

    cout << "\nChi-Square Components:\n";
    for (auto& p : expectedProbs) {
        int observed = patternFreq[p.first];
        double expected = numGroups * p.second;

        double diff = observed - expected;
        chi_square += (diff * diff) / expected;

        cout << setw(20) << left << p.first 
             << "O=" << observed << ", E=" << fixed << setprecision(2) << expected 
             << ", contrib=" << (diff * diff) / expected << endl;
    }

    cout << "\nChi-Square Statistic: " << fixed << setprecision(4) << chi_square << endl;

    int degrees_of_freedom = expectedProbs.size() - 1;  // k - 1
    cout << "Degrees of freedom: " << degrees_of_freedom << endl;
    cout << "Compare with chi-square critical value for df = " << degrees_of_freedom << " at 0.05 significance level: ~9.488\n";

    if (chi_square < 9.488)
        cout << "Sequence passes the Poker test (likely independent/random).\n";
    else
        cout << "Sequence fails the Poker test (may not be truly random).\n";

    return 0;
}
