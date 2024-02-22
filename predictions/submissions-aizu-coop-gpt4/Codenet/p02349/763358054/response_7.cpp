#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int S[n+1] = {0};

    for (int i = 0; i < q; i++) {
        bool op;
        cin >> op;
        if (op) {
            int k;
            cin >> k;
            int ans = 0;
            for (; k > 0; k -= k & -k)
                ans += S[k];
            cout << ans << '\n';
        } else {
            int s, t, x;
            cin >> s >> t >> x;
            for (; s <= n; s += s & -s)
                S[s] += x;
            for (t = t+1; t <= n; t += t & -t)
                S[t] -= x;
        }
    }

    return 0;
}