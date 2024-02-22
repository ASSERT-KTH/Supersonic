#include <iostream>
#include <vector>
using namespace std;

int main() {
    for (long long i, n, s, a; cin >> n && n != 0; cout << a << endl) {
        vector<long long> j(n);
        for (i = s = 0; i < n; i++) {
            s += (cin >> a);
        }
        for (i = n; i > 1; i--) {
            cin >> j[i];
        }
        sort(j.begin() + 1, j.end());
        for (; n > 0; s += j[n--]) {
            a = max(n * s, a);
        }
    }
    return 0;
}