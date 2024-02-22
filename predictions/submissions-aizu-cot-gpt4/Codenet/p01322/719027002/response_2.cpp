#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;
    map<string, int> o;
    string l;
    for (;;) {
        cin >> n >> m;
        if (!n && !m)
            break;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> l;
            int val;
            cin >> val;
            o[l] = val;
        }
        for (int i = 0; i < m; i++) {
            cin >> l;
            if (o.find(l) != o.end()) {
                ans += o[l];
            }
        }
        cout << ans << endl;
        o.clear();
    }
}