#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

ll cubicRoot(ll x) {
    ll l = 0, r = 1e6;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (m * m * m > x) r = m;
        else l = m;
    }
    return l;
}

int main() {
    ll z;
    while (cin >> z && z) {
        ll ans = 0;
        ll limit = cubicRoot(z*z*z);
        for (ll x = 1; x <= limit; x++) {
            ll y = cubicRoot(z*z*z - x*x*x);
            ans = max(ans, x*x*x + y*y*y);
        }
        cout << z*z*z - ans << '\n';
    }
}