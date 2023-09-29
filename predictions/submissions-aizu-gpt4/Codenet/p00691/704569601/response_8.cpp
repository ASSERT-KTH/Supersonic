#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  ll z;
  while (cin >> z && z) {
    ll ans = 0;
    ll z_cube = z * z * z;
    for (ll x = 1; x * x * x <= z_cube; x++) {
      ll x_cube = x * x * x;
      for (ll y = x; y * y * y + x_cube <= z_cube; y++) {
        ans = max(ans, x_cube + y * y * y);
      }
    }
    cout << z_cube - ans << endl;
  }
}