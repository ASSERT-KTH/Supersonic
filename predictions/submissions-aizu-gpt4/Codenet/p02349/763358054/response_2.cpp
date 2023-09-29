#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> S;
int n, q;

void update(int idx, ll val) {
    for (; idx <= n; idx += idx & -idx)
        S[idx] += val;
}

ll query(int idx) {
    ll sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += S[idx];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> q;
    S.resize(n+1, 0);
    
    while(q--) {
        bool op;
        cin >> op;
        
        if (op) {
            int k;
            cin >> k;
            cout << query(k) << '\n';
        } else {
            int s, t;
            ll x;
            cin >> s >> t >> x;
            update(s, x);
            if(t+1 <= n)
                update(t+1, -x);
        }
    }
    return 0;
}