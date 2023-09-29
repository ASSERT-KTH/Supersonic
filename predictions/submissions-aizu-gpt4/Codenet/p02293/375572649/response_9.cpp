#include <iostream>
#include <complex>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::complex<double> a, b, c, d, k;
    while (n--) {
        std::cin >> a.real() >> a.imag() >> b.real() >> b.imag();
        std::cin >> c.real() >> c.imag() >> d.real() >> d.imag();
        
        k = (b - a) * std::conj(d - c);
        if(std::imag(k) == 0.0) std::cout << "2\n";
        else if(std::real(k) == 0.0) std::cout << "1\n";
        else std::cout << "0\n";
    }
    return 0;
}