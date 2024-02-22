#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll z;
  while (cin >> z && z) {
    ll z_cube = z * z * z;  // Pre-calculating z's cube
    ll ans = 0;
    for (ll x = 1; x * x * x <= z_cube; x++) {
      ll x_cube = x * x * x;  // Storing x's cube
      for (ll y = x; x_cube + y * y * y <= z_cube; y++) {  // y starts from x
        ll y_cube = y * y * y;  // Storing y's cube
        ans = max(ans, x_cube + y_cube);
      }
    }
    cout << z_cube - ans << endl;
  }
}