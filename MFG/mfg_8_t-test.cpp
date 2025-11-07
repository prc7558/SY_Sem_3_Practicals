/* A manufacturer claims that the mean lifetime of a certain type of bulb is at least 1500 hours.
A consumer agency tests a random sample of 25 bulbs and finds that the sample mean is 1470 hours with a sample standard deviation of 80 hours. */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double pop_mean = 1500;    // Claimed population mean
    double sam_mean = 1470;    // Sample mean
    double sam_sd = 80;        // Sample standard deviation
    int sam_size = 25;         // Sample size
    double t_test, crit_val;

    // Degrees of freedom
    int df = sam_size - 1;

    // For 5% significance level (one-tailed, left test), df = 24
    // Critical value (from t-table): t_0.05,24 = -1.711
    crit_val = -1.711;

    cout << "Degrees of Freedom = " << df << endl;
    cout << "Critical t-Value = " << crit_val << endl;

    // t-test formula
    t_test = (sam_mean - pop_mean) / (sam_sd / sqrt(sam_size));
    cout << "Test statistic (t) = " << t_test << endl;

    cout << "\nNull Hypothesis (H0): Mean lifetime >= 1500 hours (μ ≥ 1500)";
    cout << "\nAlternative Hypothesis (Ha): Mean lifetime < 1500 hours (μ < 1500)\n";

    // Decision rule
    if (t_test < crit_val)
        cout << "\nManufacturer's claim is REJECTED." << endl;
    else
        cout << "\nManufacturer's claim is ACCEPTED." << endl;

    return 0;
}
