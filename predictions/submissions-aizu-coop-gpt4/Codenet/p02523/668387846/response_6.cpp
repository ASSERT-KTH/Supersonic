#include <cmath>
#include <complex>
#include <iostream>

using namespace std;

int main() {
    double real1, imag1, real2, imag2;
    
    // Read the real and imaginary parts of the complex numbers
    if (!(cin >> real1 >> imag1 >> real2 >> imag2)) {
        cout << "Invalid input!" << endl;
        return 1; // Non-zero exit code to indicate an error
    }

    // Initialize the complex numbers
    complex<double> P1(real1, imag1);
    complex<double> P2(real2, imag2);

    printf("%.5f\n", abs(P1 - P2));
    return 0;
}