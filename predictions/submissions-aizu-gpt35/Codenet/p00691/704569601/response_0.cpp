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
  ll z, max_y, max_x;
  while (cin >> z && z) {
    max_y = pow(z * z * z, 1.0 / 3.0);
    max_x = pow(z * z * z - 1, 1.0 / 3.0);
    ll ans = 0;
    for (ll x = 1; x <= max_x; x++)
      for (ll y = 1; y <= max_y; y++)
        if (x * x * x + y * y * y <= z * z * z)
          ans = max(ans, x * x * x + y * y * y);
    cout << z * z * z - ans << endl;
  }
}