#include <iostream>
#include <unordered_map>
#include <cstring>

using namespace std;

int main() {
    int n, m, o[100];
    string b[100];
    string l;
    int ans;
    for (;;) {
        cin >> n >> m;
        if (!n && !m)
            break;
        ans = 0;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> b[i] >> o[i];
            mp[b[i]] = o[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> l;
            if (mp.find(l) != mp.end()) {
                ans += mp[l];
            }
            else {
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    if (b[j].size() != l.size()) {
                        continue;
                    }
                    bool f = true;
                    for (int k = 0; k < 8; k++) {
                        if (b[j][k] != '*' && b[j][k] != l[k]) {
                            f = false;
                            break;
                        }
                    }
                    if (f) {
                        cnt += o[j];
                    }
                }
                ans += cnt;
                mp[l] = cnt;
            }
        }
        cout << ans << endl;
    }
}