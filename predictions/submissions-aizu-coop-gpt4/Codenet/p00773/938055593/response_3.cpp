#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

int main() {
    int x, y, s;
    while (cin >> x >> y >> s && (x || y || s)) {
        list<pair<int, int>> tax;
        int maxi = 0, a = 1, b;
        while (a < s) {
            int temp = (int)((a * (100 + x)) / 100.0);
            b = (s - temp + 1) / ((100 + x) / 100.0);
            if ((temp + (int)((b * (100 + x)) / 100.0)) == s && b != 0) {
                tax.push_back(make_pair(a, b));
                maxi = max(maxi, (int)((a * (100 + y)) / 100.0) +
                                 (int)((b * (100 + y)) / 100.0));
            }
            a++;
        }
        cout << maxi << endl;
    }
    return 0;
}