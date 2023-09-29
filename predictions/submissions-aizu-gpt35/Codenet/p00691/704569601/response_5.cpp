#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
ll b_pow(ll x, ll n) {
  return n ? n == 1 ? x : b_pow(x * x, n >> 1) * (n & 1 ? x : 1) : 1;
}
int main() {
  ll z;
  while (cin >> z && z) {
    ll ans = 0;
    ll cube_root = cbrt(z * z * z);
    for (ll x = 1; x <= cube_root; x++) {
      ll y_cube = z * z * z - x * x * x;
      ll y = cbrt(y_cube);
      if (y * y * y != y_cube) y++;
      if (y > cube_root) break;
      ans = max(ans, x * x * x + y * y * y);
    }
    cout << z * z * z - ans << endl;
  }
}