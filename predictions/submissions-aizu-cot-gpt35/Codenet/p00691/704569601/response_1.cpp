#include <cmath>
#include <iostream>

typedef long long ll;

int main() {
  ll z;
  while (std::cin >> z && z) {
    ll ans = 0;
    ll z_cube = z * z * z;

    ll max_x = std::cbrt(z_cube);

    for (ll x = 1; x <= max_x; x++) {
      ll max_y = std::cbrt(z_cube - x * x * x);
      for (ll y = 1; y <= max_y; y++) {
        ans = std::max(ans, x * x * x + y * y * y);
      }
    }

    std::cout << z_cube - ans << std::endl;
  }
}