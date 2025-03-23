#include<iostream>
//#include <stdio.h>
#include <math.h>
//#include <conio.h>
using namespace std;

int main() {
    int n, xp;

    cout<<"Enter number of points: ";
    cin>>n;

    float h[n], x[n], fx[n], u[n], v[n], b[n], m[n][n], r[n], e[n];
    float val, pivot, sum;

    cout<<"Enter the value at which interpolated value is needed: ";
    cin>>xp;

    for (int i = 0; i < n; i++) {
        cout<<"Enter the value of x and fx at i = "<< i<<"->:)	";
        cin>>x[i]>>fx[i];
    }

    for (int i = 0; i < n - 1; i++) {
        h[i] = x[i + 1] - x[i];
        b[i] = (fx[i + 1] - fx[i]) / h[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        u[i] = 2 * (h[i - 1] + h[i]);
        v[i] = 6 * (b[i] - b[i - 1]);
    }

    // Construction of matrix in LHS
    for (int i = 1; i < n - 1; i++) {
        m[i][i] = u[i];
        if (i != 1) {
            m[i][i - 1] = h[i - 1];
            m[i - 1][i] = h[i - 1];
        }
        r[i] = v[i];  // RHS vector
    }

    for (int k = 1; k < n - 2; k++) {  // Forward Elimination
        pivot = m[k][k];
        if (pivot < 0.000001) {
            cout<<"Method failed!\n";
        } else {
            for (int i = k + 1; i < n - 1; i++) {
                for (int j = 1; j < n - 1; j++) {
                    m[i][j] = m[i][j] - (m[k][j] * m[i][k]) / pivot;
                }
                r[i] = r[i] - (r[k] * m[i][k]) / pivot;
            }
        }
    }

    e[n - 2] = r[n - 2] / m[n - 2][n - 2];

    for (int i = n - 3; i >= 1; i--) {  // Backward Substitution
        sum = 0;
        for (int j = i + 1; j < n - 1; j++) {
            sum = sum + m[i][j] * e[j];
        }
        e[i] = (r[i] - sum) / m[i][i];
    }

    // Locate interval in which interpolation point lies and compute interpolation value
    for (int i = 0; i <= n - 2; i++) {
        if (xp <= x[i]) {
            val = (e[i + 1] / (6 * h[i])) * (xp - x[i]) * (xp - x[i]) * (xp - x[i]) +
                  (e[i] / (6 * h[i])) * (x[i + 1] - xp) * (x[i + 1] - xp) * (x[i + 1] - xp) +
                  (((fx[i + 1] / h[i]) - ((e[i + 1] * h[i]) / 6)) * (xp - x[i])) +
                  (((fx[i] / h[i]) - ((e[i] * h[i]) / 6)) * (x[i + 1] - xp));
            break;
        }
    }

    cout<<"\nInterpolated Value = "<<val<<endl; 

    return 0;
}