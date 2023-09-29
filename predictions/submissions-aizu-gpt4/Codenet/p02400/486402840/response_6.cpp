#include <iostream>
using namespace std;

int main() {
    static constexpr double PI = 3.141592653589;
    double r;
    cin >> r;
    double s = r * r * PI;
    double l = 2 * r * PI;
    cout.precision(8);
    cout << fixed << s << " " << l << endl;
}