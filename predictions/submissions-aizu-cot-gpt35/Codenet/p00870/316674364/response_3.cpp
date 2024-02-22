#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m, n != 0) {
        vector<string> patterns(n);
        for (int i = 0; i < n; i++) {
            cin >> patterns[i];
        }

        string text;
        for (int i = 0; i < m; i++) {
            string a;
            cin >> a;
            text += a;
        }

        int ans = 0;
        for (int i = 0; i <= text.size(); i++) {
            vector<bool> vis(n, false);
            vis[0] = true;
            for (int j = 0; j < n; j++) {
                if (!vis[j]) continue;
                for (int k = 0; k < n; k++) {
                    if ((i + patterns[k].size() <= text.size()) && (patterns[k] == text.substr(i, patterns[k].size()))) {
                        vis[j | (1 << k)] = true;
                    }
                }
            }
            ans += vis[(1 << n) - 1];
        }

        cout << ans << endl;
    }

    return 0;
}