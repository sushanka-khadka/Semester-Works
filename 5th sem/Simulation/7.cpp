// markov chain to predict weather condition.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

// Weather states
enum Weather { Sunny, Cloudy, Rainy };

// Transition matrix
const double transition[3][3] = {
    {0.6, 0.3, 0.1},  // From Sunny
    {0.2, 0.5, 0.3},  // From Cloudy
    {0.3, 0.4, 0.3}   // From Rainy
};

// Convert state to string
string getWeatherName(Weather state) {
    switch (state) {
        case Sunny: return "Sunny";
        case Cloudy: return "Cloudy";
        case Rainy: return "Rainy";
        default: return "Unknown";
    }
}

// Get next state based on current state and probabilities
Weather getNextWeather(Weather current) {
    double randVal = (double)rand() / RAND_MAX;
    double cumulative = 0.0;

    for (int i = 0; i < 3; ++i) {
        cumulative += transition[current][i];
        if (randVal < cumulative) {
            return static_cast<Weather>(i);
        }
    }

    // fallback
    return Sunny;
}

int main() {
    srand(time(0));  // Seed RNG

    int days;
    cout << "----- Markov Chain(Weather Prediction) ----\n";
	cout << "Enter number of days to simulate: ";
    cin >> days;

    Weather current = Sunny;  // Initial state
    cout << "Day 0: " << getWeatherName(current) << endl;

    for (int i = 1; i <= days; ++i) {
        current = getNextWeather(current);
        cout << "Day " << i << ": " << getWeatherName(current) << endl;
    }

    return 0;
}
