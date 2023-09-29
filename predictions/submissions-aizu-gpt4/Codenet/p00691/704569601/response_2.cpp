#include <iostream>
typedef long long ll;

ll b_pow(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

int main() {
    ll z;
    while (std::cin >> z && z) {
        ll z_cubed = b_pow(z, 3);
        ll ans = 0;
        for (ll x = 1; x * x * x <= z_cubed; x++) {
            ll x_cubed = b_pow(x, 3);
            for (ll y = x; y * y * y + x_cubed <= z_cubed; y++)
                ans = std::max(ans, x_cubed + b_pow(y, 3));
        }
        std::cout << z_cubed - ans << std::endl;
    }
}