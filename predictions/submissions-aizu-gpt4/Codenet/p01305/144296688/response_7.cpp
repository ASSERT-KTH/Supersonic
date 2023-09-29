#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        vector<int> a(18);
        for (int i = 0; i < 18; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        long long sum1 = 0, sum2 = 0;
        for (int i = 0; i < 18; i += 2) sum1 += a[i];
        for (int i = 1; i < 18; i += 2) sum2 += a[i];
        cout << (sum1 > sum2 ? "1 0\n" : "0 1\n");
    }
    return 0;
}