#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

ll b_pow(ll x, ll n) {
  ll result = 1;
  while (n > 0) {
    if (n & 1) {
      result *= x;
    }
    x *= x;
    n >>= 1;
  }
  return result;
}

int main() {
  ll z;
  while (cin >> z && z) {
    ll z_cubed = z * z * z;
    ll ans = 0;
    for (ll x = 1; x * x * x <= z_cubed; x++) {
      ll x_cubed = x * x * x;
      ll y = cbrt(z_cubed - x_cubed);
      ans = max(ans, x_cubed + y * y * y);
    }
    cout << z_cubed - ans << endl;
  }
}