#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int x, y, s;
    while (cin >> x >> y >> s && (x || y || s)) {
        int maxi = 0;
        for (int a = 1; a < s; ++a) {
            int b = (s * 100 - a * x) / (100 + x);
            if (a * x + b * x == s * 100) {
                maxi = max(maxi, a * y / 100 + b * y / 100);
            }
        }
        cout << maxi << '\n';
    }
    return 0;
}