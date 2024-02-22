#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    while (true) {
        cin >> n;
        if (n == 0)
            break;

        vector<long long> j(n);
        long long s = 0, a = -1e18, t;
        for (long long i = 0; i < n; i++) {
            cin >> t;
            s += t;
            j[i] = t;
        }
        sort(j.begin(), j.end());

        for (long long i = n - 1; i >= 0; i--) {
            a = max(a, (i + 1) * s);
            s -= j[i];
        }
        cout << a << "\n";
    }

    return 0;
}