#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m, n || m) {
        vector<int> o(n);
        unordered_map<string, int> b;
        string l;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            cin >> l >> o[i];
            b[l] = i;
        }

        while (m--) {
            cin >> l;
            for (int mask = 0; mask < (1 << 8); mask++) {
                string cur = l;
                for (int i = 0; i < 8; i++) {
                    if (mask & (1 << i)) cur[i] = '*';
                }
                auto it = b.find(cur);
                if (it != b.end()) {
                    ans += o[it->second];
                    break;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}