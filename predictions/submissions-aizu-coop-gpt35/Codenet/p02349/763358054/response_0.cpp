#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    // Disable synchronization between C and C++ standard streams for faster input/output
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<ll> S(n + 1, 0); // Use std::vector instead of fixed-size array

    while (q--) {
        bool op;
        cin >> op;

        if (op) {
            int k;
            cin >> k;

            ll ans = 0;
            for (int i = k; i > 0; i -= i & -i) {
                ans += S[i];
            }

            cout << ans << '\n';
        } else {
            int s, t, x;
            cin >> s >> t >> x;

            // Combine multiple updates into a single update
            for (int i = s; i <= n; i += i & -i) {
                S[i] += x;
            }
            for (int i = t + 1; i <= n; i += i & -i) {
                S[i] -= x;
            }
        }
    }

    return 0;
}