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
    ll z_cubed = z * z * z;
    for (ll x = 1; x <= cbrt(z_cubed); x++)
      for (ll y = 1; y <= cbrt(z_cubed - b_pow(x, 3)); y++)
        ans = max(ans, b_pow(x, 3) + b_pow(y, 3));
    cout << z_cubed - ans << endl;
  }
}