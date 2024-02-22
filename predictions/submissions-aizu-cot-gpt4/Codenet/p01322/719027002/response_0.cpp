#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, m;
    for (;;) {
        cin >> n >> m;
        if (!n && !m)
            break;
        unordered_map<string, int> b;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            string s;
            int o;
            cin >> s >> o;
            b[s] = o;
        }
        for (int i = 0; i < m; i++) {
            string l;
            cin >> l;
            if (b.find(l) != b.end())
                ans += b[l];
        }
        cout << ans << endl;
    }
}