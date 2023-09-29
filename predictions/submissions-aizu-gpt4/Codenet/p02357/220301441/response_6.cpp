#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> dp(n);
    multiset<int> window;
    for (int i = 0; i < l; ++i) window.insert(a[i]);
    dp[l - 1] = *window.begin();

    for (int i = l; i < n; ++i) {
        window.erase(window.find(a[i - l]));
        window.insert(a[i]);
        dp[i] = *window.begin();
    }

    for (int i = l - 1; i < n; ++i) {
        cout << dp[i] << ' ';
    }

    return 0;
}