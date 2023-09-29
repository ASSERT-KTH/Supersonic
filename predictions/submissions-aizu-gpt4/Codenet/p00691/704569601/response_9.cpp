#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll cubic_root(ll n) {
    ll lo = 1, hi = 1e6;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (mid * mid * mid <= n) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

int main() {
    ll z;
    while (cin >> z && z) {
        ll z_cubed = z * z * z;
        ll ans = 0;
        for (ll x = 1; x <= cubic_root(z_cubed); x++) {
            ll y = cubic_root(z_cubed - x * x * x);
            ans = max(ans, x * x * x + y * y * y);
        }
        cout << z_cubed - ans << endl;
    }
}