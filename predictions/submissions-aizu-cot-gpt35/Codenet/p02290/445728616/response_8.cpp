#include <iostream>
#include <complex>
using namespace std;

typedef complex<double> P;

P project(P a, P b, P c) {
    b -= a, c -= a;
    return a + b * real(c / b);
}

int main() {
    double ax, ay, bx, by;
    int n;
    
    cin >> ax >> ay >> bx >> by >> n;
    P ab = P(bx - ax, by - ay);

    while (n--) {
        double cx, cy;
        cin >> cx >> cy;
        P ac = P(cx - ax, cy - ay);
        P p = ax + ab * real(ac / ab);
        cout << fixed << setprecision(8) << p.real() << " " << p.imag() << "\n";
    }

    return 0;
}