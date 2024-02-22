#include <cstdio>

// Custom data structure for complex numbers
struct Complex {
    double real;
    double imag;
};

// Function to calculate the absolute value of a complex number
double abs(const Complex& c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

int main() {
    Complex P1, P2;
    scanf("%lf %lf %lf %lf", &P1.real, &P1.imag, &P2.real, &P2.imag);
    printf("%.5f\n", abs(P1 - P2));
    return 0;
}