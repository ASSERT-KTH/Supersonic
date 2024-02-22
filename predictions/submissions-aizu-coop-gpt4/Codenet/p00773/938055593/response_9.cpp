#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

int main() {
    int x, y, s;
    while (cin >> x >> y >> s && (x || y || s)) {
        list<pair<int, int>> tax;
        int maxi = 0;

        for (int a = 1; a < s; ++a) {
            int b = (s * 100 - a * (100 + x) + 99) / (100 + x);

            if (a * (100 + x) / 100 + b * (100 + x) / 100 == s && b != 0) {
                int tax_a = a * (100 + y) / 100;
                int tax_b = b * (100 + y) / 100;

                tax.push_back(make_pair(a, b));
                maxi = max(maxi, tax_a + tax_b);
            }
        }
        cout << maxi << endl;
    }
    return 0;
}