#include <iostream>
#include <math.h>
#define M_PI 3.14159265358979323846

using namespace std;

double f(double mu, double sigma2, double x)
{
    //Use mu, sigma2 (sigma squared), and x to code the 1-dimensional Gaussian
    double prob = 1.0 / sqrt(2.0 * M_PI * sigma2) * exp(-0.5 * pow((x - mu), 2.0) / sigma2);
    return prob;
}

int main()
{
    cout << f(10.0, 4.0, 8.0) << endl;
    return 0;
}

/*
NOTE:
When using Kalman Filter, Predicted Motion, Sensor Mearsurement and Estimated State of Robot are all represented by Gaussian distribution. 
The Gausssian distribution is the foundation of the Kalman Filter.
*/
