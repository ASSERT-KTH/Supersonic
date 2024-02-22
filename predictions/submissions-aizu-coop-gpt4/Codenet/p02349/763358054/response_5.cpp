#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    const int maxn = 100005;
    ll S[maxn] = {0};
    int n, q;

    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        bool op;
        cin >> op;

        if (op) {
            int k;
            cin >> k;
            ll ans = 0;
            for (int *i = &S[k]; i > S; i -= *i & -*i)
                ans += *i;
            cout << ans << '\n';
        } else {
            int s, t, x;
            cin >> s >> t >> x;
            for (int *i = &S[s]; i <= &S[n]; i += *i & -*i)
                *i += x;
            for (int *i = &S[t + 1]; i <= &S[n]; i += *i & -*i)
                *i -= x;
        }
    }

    return 0;
}