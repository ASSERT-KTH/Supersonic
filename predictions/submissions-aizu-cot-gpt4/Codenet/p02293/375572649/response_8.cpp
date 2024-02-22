#include <iostream>
#include <complex>
using namespace std;

typedef complex<double> P;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
     
    int n;
    cin >> n;
    while (n--) {
        double ax, ay, bx, by, cx, cy, dx, dy;
        cin >> ax >> ay >> bx >> by;
        cin >> cx >> cy >> dx >> dy;
        
        double bx_minus_ax = bx - ax;
        double by_minus_ay = by - ay;
        double dx_minus_cx = dx - cx;
        double cy_minus_dy = cy - dy;

        P k = P(bx_minus_ax, by_minus_ay) * P(dx_minus_cx, cy_minus_dy);
        
        if (k.imag() == 0)
            cout << "2\n";
        else if (k.real() == 0)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}