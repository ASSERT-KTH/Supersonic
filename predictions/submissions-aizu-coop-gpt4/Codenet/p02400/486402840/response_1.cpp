#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Define constant for pi
    const double PI = 3.141592653589;

    // Input the radius
    double radius;
    cin >> radius;

    // Calculate and print the area
    cout << setprecision(8) << fixed << PI * radius * radius << " ";

    // Calculate and print the circumference
    cout << 2 * PI * radius << endl;

    return 0;
}