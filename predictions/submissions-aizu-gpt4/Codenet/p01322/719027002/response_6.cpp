#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    vector<int> o(100);
    unordered_map<string, int> b;
    string l;
    int ans;

    while (true) {
        cin >> n >> m;
        if (!n && !m) break;

        ans = 0;
        b.clear();
        for (int i = 0; i < n; i++) {
            cin >> l >> o[i];
            b[l] = o[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> l;
            if(b.find(l) != b.end()) ans += b[l];
        }
        cout << ans << '\n';
    }
    return 0;
}