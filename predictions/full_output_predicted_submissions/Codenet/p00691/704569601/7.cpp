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
    for (ll x = 1; x * x * x <= z * z * z; x++)
      for (ll y = 1; y * y + x * x * x <= z * z * z; y++)
        ans = max(ans, x * x * x + y * y * y);
    cout << z * z * z - ans << endl;
  }
}
