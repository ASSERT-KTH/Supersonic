#include <cmath>
#include <complex>
#include <iostream>
using namespace std;

int main() {
    double real1, imag1, real2, imag2;
    cin >> real1 >> imag1 >> real2 >> imag2;
    complex<double> P1(real1, imag1);
    complex<double> P2(real2, imag2);
    cout << fixed << setprecision(5) << abs(P1 - P2) << endl;
    return 0;
}