#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll z;
  while (cin >> z && z) {
    ll z_cube = z * z * z;
    ll ans = 0;
    for (ll x = 1; ; x++) {
      ll x_cube = x * x * x;
      if (x_cube > z_cube)
        break;
      for (ll y = 1; ; y++) {
        ll y_cube = y * y * y;
        if (x_cube + y_cube > z_cube)
          break;
        ans = max(ans, x_cube + y_cube);
      }
    }
    cout << z_cube - ans << endl;
  }
}