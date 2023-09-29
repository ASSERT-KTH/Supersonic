#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    while(cin >> n && n) {
        vector<long long> j(n);
        long long s = 0, a = 0;
        
        for (long long i = 0; i < n; ++i) {
            cin >> j[i];
            s += j[i];
        }

        sort(j.begin(), j.end());

        for (long long i = n; i > 0; --i) {
            a = max(i * s, a);
            s -= j[n - i];
        }

        cout << a << "\n";
    }

    return 0;
}