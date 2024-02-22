#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ll z;
  while (cin >> z && z) {
    ll z_cubed = z * z * z;
    ll ans = 0;
    for (ll x = 1; x * x * x <= z_cubed; x++) {
      ll x_cubed = x * x * x;
      for (ll y = x; x_cubed + y * y * y <= z_cubed; y++) {
        ll y_cubed = y * y * y;
        ans = max(ans, x_cubed + y_cubed);
      }
    }
    cout << z_cubed - ans << endl;
  }
}