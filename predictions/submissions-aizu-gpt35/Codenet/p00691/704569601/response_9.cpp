#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

ll b_pow(ll x, ll n) {
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return x;
  }
  ll tmp = b_pow(x, n >> 1);
  if (n & 1) {
    return x * tmp * tmp;
  }
  return tmp * tmp;
}

int main() {
  ll z;
  while (cin >> z && z) {
    ll ans = 0;
    ll limit = cbrt(z) + 1;
    for (ll x = 1; x <= limit; x++) {
      ll y_limit = cbrt(z - b_pow(x, 3));
      for (ll y = x; y <= y_limit; y++) {
        ans = max(ans, b_pow(x, 3) + b_pow(y, 3));
      }
    }
    cout << b_pow(z, 3) - ans << endl;
  }
  return 0;
}