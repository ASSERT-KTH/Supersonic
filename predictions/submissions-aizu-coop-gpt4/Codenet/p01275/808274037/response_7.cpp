#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    while (cin >> k, k) {
        string s, t;
        cin >> s >> t;

        vector<int> dif(k);
        for (int i = 0; i < k; i++) {
            dif[i] = ((int)(t[i] - s[i]) + 10) % 10;
        }
        sort(dif.begin(), dif.end());

        int ans = k;
        for (int i = 0; i < k; ++i) {
            ans = min(ans, i + k - (upper_bound(dif.begin(), dif.end(), dif[i]) - dif.begin()));
        }

        cout << ans << "\n";
    }
    return 0;
}