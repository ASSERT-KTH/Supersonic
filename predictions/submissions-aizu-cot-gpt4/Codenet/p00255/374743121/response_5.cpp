#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    while (cin >> n && n != 0) {
        vector<long long> j(n);
        long long s = 0, a = 0;
        for (long long i = 0; i < n; i++) {
            cin >> j[i];
            s += j[i];
        }
        sort(j.begin(), j.end());
        long long value = n * s;
        for (long long i = n-1; i >= 0; i--) {
            a = max(value, a);
            s -= j[i];
            value = i * s;
        }
        cout << a << endl;
    }
    return 0;
}