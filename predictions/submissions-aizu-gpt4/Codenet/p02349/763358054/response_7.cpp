#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
ll S[maxn];
int n, q;

inline void update(int idx, ll val) {
    while (idx <= n) {
        S[idx] += val;
        idx += (idx & -idx);
    }
}

inline ll query(int idx) {
    ll sum = 0;
    while (idx > 0) {
        sum += S[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        bool op;
        cin >> op;
        if (op) {
            int k;
            cin >> k;
            cout << query(k) << '\n';
        } else {
            int s, t, x;
            cin >> s >> t >> x;
            update(s, x);
            if (t + 1 <= n) update(t + 1, -x);
        }
    }
}