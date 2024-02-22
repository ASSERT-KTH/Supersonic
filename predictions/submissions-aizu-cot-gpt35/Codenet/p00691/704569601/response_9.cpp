#include <iostream>
using namespace std;

typedef long long ll;

ll b_pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res *= x;
    }
    x *= x;
    n >>= 1;
  }
  return res;
}

int main() {
  ll z;
  while (cin >> z && z) {
    ll ans = 0;
    ll limit = cbrt(z);
    for (ll x = 1; x <= limit; x++) {
      for (ll y = 1; y <= limit; y++) {
        ll sum = b_pow(x, 3) + b_pow(y, 3);
        if (sum <= b_pow(z, 3)) {
          ans = max(ans, sum);
        } else {
          break;
        }
      }
    }
    cout << b_pow(z, 3) - ans << endl;
  }
  return 0;
}