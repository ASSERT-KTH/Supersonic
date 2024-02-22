#include <cmath>
#include <iostream>

typedef long long ll;

int main() {
  ll z;
  while (std::cin >> z && z) {
    ll ans = 0;
    ll z_cubed = z * z * z;

    for (ll x = 1; x * x * x <= z_cubed; x++) {
      ll x_cubed = x * x * x;

      for (ll y = 1; y_cubed <= z_cubed - x_cubed; y++) {
        ll y_cubed = y * y * y;
        ll temp = x_cubed + y_cubed;
        ans = std::max(ans, temp);
      }
    }

    std::cout << z_cubed - ans << std::endl;
  }
}