#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ll z;
  while (cin >> z && z) {
    ll ans = 0;
    ll z_cubed = z * z * z;
    ll max_x = cbrt(z_cubed); // Compute the cube root of z_cubed
    ll max_y = cbrt(z_cubed - 1); // Compute the cube root of z_cubed - 1

    for (ll x = 1; x <= max_x; x++) {
      ll x_cubed = x * x * x;
      ll max_y_with_x = cbrt(z_cubed - x_cubed);
      for (ll y = 1; y <= max_y_with_x; y++) {
        ll y_cubed = y * y * y;
        ll sum_cubed = x_cubed + y_cubed;
        if (sum_cubed <= z_cubed && sum_cubed > ans) {
          ans = sum_cubed;
        }
      }
    }

    cout << z_cubed - ans << endl;
  }
}