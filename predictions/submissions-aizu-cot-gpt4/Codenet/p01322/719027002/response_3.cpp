#include <iostream>
#include <algorithm>
using namespace std;

char b[100][9];
int o[100];

int main() {
    int n, m, ans;
    for (;;) {
        cin >> n >> m;
        if (!n && !m)
            break;
        ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 8; j++)
                cin >> b[i][j];
            cin >> o[i];
        }
        sort(b, b + n);
        for (int i = 0; i < m; i++) {
            char l[9];
            for (int j = 0; j < 8; j++)
                cin >> l[j];
            int idx = lower_bound(b, b + n, l) - b;
            if (idx < n && equal(b[idx], b[idx] + 8, l))
                ans += o[idx];
        }
        cout << ans << endl;
    }
    return 0;
}