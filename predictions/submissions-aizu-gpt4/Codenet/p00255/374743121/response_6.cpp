#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, a;
    while (cin >> n && n) {
        vector<long long> j(n);
        long long s = 0;
        for (long long i = 0; i < n; ++i) {
            cin >> a;
            s += a;
        }
        for (long long i = 0; i < n; ++i) {
            cin >> j[i];
        }
        sort(j.begin(), j.end());
        a = 0;
        for (long long i = n - 1; i >= 0; --i) {
            a = max((i + 1) * s, a);
            s -= j[i];
        }
        cout << a << "\n";
    }
    return 0;
}