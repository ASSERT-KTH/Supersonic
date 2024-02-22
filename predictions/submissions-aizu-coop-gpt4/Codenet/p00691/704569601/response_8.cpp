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
    ll z_cube = z * z * z; // Store z^3 in a variable
    ll ans = 0;
    ll limit = cbrt(z); // Compute cube root of z
    for (ll x = 1; x <= limit; x++) {
      ll x_cube = x * x * x; // Store x^3 in a variable
      for (ll y = 1; y <= limit; y++) {
        ll y_cube = y * y * y; // Store y^3 in a variable
        if(x_cube + y_cube > z_cube) break; // Break if sum of cubes is larger than z_cube
        ans = max(ans, x_cube + y_cube);
      }
    }
    cout << z_cube - ans << endl;
  }
}