#include <iostream>
#include <complex>

typedef std::complex<double> P;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
  
    int n;
    double ax, ay, bx, by, cx, cy, dx, dy;
    std::cin >> n;
    while (n--) {
        std::cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
        P k = P(bx - ax, by - ay) * P(dx - cx, dy - cy);
        if (std::imag(k) == 0)
            std::cout << "2\n";
        else if (std::real(k) == 0)
            std::cout << "1\n";
        else
            std::cout << "0\n";
    }
    return 0;
}