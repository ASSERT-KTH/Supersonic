#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
ll pow3(ll x) {
  return x*x*x;
}
int main() {
  ll z;
  while (cin >> z && z) {
    ll ans = 0;
    ll z3 = pow3(z);
    for (ll x = 1; pow3(x) <= z3; x++) {
      for (ll y = 1; y <= x; y++) {
        ll y3 = pow3(y);
        ll x3 = pow3(x);
        if (x3 + y3 > z3) break;
        ans = max(ans, x3 + y3);
      }
    }
    cout << z3 - ans << endl;
  }
}