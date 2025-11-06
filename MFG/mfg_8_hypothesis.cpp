/* PROBLEM STATEMENT: A manufacturer claims that the mean lifetime
 * of a certain type of battery is at least 1000 hours.
 * A consumer agency tests a random sample of 36 batteries & finds the
 * sample mean is 980 hours with a population standard deviation of 60 hours.
Perform following tasks-
• State the null and alternative hypotheses.
• Perform a hypothesis test at the 5% significance level.
• Find the critical value and the test statistic.
• Conclude whether the claim can be accepted or rejected.*/

#include<iostream>
#include<cmath>
using namespace std;

int main() {
	double pop_mean = 1000;
	double sam_mean = 980;
	double pop_sd = 60;
	double z_test, crit_val;
	int sam_size = 36;
	
	// Left-tailed test at 5% significance level
    crit_val = -1.645;
	z_test = (sam_mean-pop_mean) * (sqrt(sam_size)/pop_sd);
	cout << "Test statistic (z) = " << z_test << endl;
	
	cout << "Null Hypothesis (H0​): The mean battery lifetime is at least 1000 hours.H0​:μ≥1000" << endl;
	cout << "Alternative Hypothesis (Ha​): The mean battery lifetime is less than 1000 hours.Ha​:μ<1000" << endl;
	
	if (z_test < crit_val) cout << "Manufacturer's claim is REJECTED." << endl;
	else cout << "Manufacturer's claim is ACCPETED." << endl;
	
	return 0;
}
