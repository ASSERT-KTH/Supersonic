#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

int main() {
    int n;
    Point a, b, c, d;
    cin >> n;
    while (n--) {
        cin >> a.x >> a.y >> b.x >> b.y;
        cin >> c.x >> c.y >> d.x >> d.y;
        double k = (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x);
        if (abs(k) < 1e-7)
            cout << "2\n";
        else if (k == 0)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}