#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> S;
int n, q;

ll query(int idx){
    ll sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += S[idx];
    return sum;
}

void update(int idx ,int val){
    for(; idx <= n; idx += idx & -idx)
        S[idx] += val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    S.resize(n+1, 0);
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
            if(t+1 <= n) update(t+1, -x);
        }
    }
    return 0;
}