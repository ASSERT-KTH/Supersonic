#include <iostream>
#include <unordered_map>
#include <cstring>

using namespace std;

const int MAX_N = 100;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    unordered_map<string, int> mp;
    string b;
    int o;
    while (cin >> n >> m && n) {
        mp.clear();
        for (int i = 0; i < n; ++i) {
            cin >> b >> o;
            mp[b] = o;
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            cin >> b;
            if (mp.count(b)) {
                ans += mp[b];
            }
        }
        cout << ans << '\n';
    }

    return 0;
}