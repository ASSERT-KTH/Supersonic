#include <iostream>
using namespace std;

constexpr double PI = 3.141592653589;

int main() {
    double r;
    cin >> r;

    double s = PI * r * r;
    double l = 2 * PI * r;

    cout.precision(9);
    cout << fixed << s << ' ' << l << '\n';
}