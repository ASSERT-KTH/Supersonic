#include <iostream>
using namespace std;

int main() {
    int x, y, s;
    while (cin >> x >> y >> s && (x || y || s)) {
        int maxi = 0, a = 1, b;
        double x_ratio = (100 + x) / 100.0;
        double y_ratio = (100 + y) / 100.0;
        while (a < s) {
            b = (s - (int)(a * x_ratio) + 1) / x_ratio;
            if ((int)(a * x_ratio) + (int)(b * x_ratio) == s && b != 0) {
                maxi = max(maxi, (int)(a * y_ratio) + (int)(b * y_ratio));
            }
            a++;
        }
        cout << maxi << endl;
    }
    return 0;
}