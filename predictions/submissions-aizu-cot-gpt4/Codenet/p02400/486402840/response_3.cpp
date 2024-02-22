#include <iostream>
#include <iomanip>
using namespace std;

const double PI = 3.141592653589;

int main() {
    double r;
    cin >> r;

    double r_doubled = r * 2;
    double area = PI * r * r;
    double circumference = PI * r_doubled;

    cout << fixed << setprecision(8) << area << " " << circumference << "\n";
}