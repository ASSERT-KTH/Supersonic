#include <iostream>
using namespace std;

int main() {
    double r, s, l;
    const double PI = 3.141592653589;
    cin >> r;
    s = r * r * PI;
    l = 2 * PI * r;
    cout.precision(8);
    cout << s << " " << l << "\n";
}