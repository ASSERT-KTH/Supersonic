#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
ll b_pow(ll x, ll n) {
  return n ? n == 1 ? x : b_pow(x, n >> 1) * b_pow(x, (n >> 1) + (n & 1)) : 1;
}
int main() {
  ll z;
  while (cin >> z && z) {
    ll ans = 0;
    ll max_y = cbrt(z * z * z - 1);
    for (ll y = 1; y <= max_y; y++) {
      ll max_x = cbrt(z * z * z - y * y * y);
      for (ll x = 1; x <= max_x; x++)
        ans = max(ans, x * x * x + y * y * y);
    }
    cout << z * z * z - ans << endl;
  }
}