#include <iostream>

typedef long long ll;

ll b_pow(ll x, ll n) {
  ll result = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      result *= x;
    }
    x *= x;
    n /= 2;
  }
  return result;
}

int main() {
  ll z;
  while (std::cin >> z && z) {
    ll max_x = 1;
    while (b_pow(max_x, 3) <= b_pow(z, 3)) {
      max_x++;
    }
    ll ans = 0;
    for (ll x = 1; x < max_x; x++) {
      ll max_y = 1;
      while (b_pow(x, 3) + b_pow(max_y, 3) <= b_pow(z, 3)) {
        max_y++;
      }
      ans = std::max(ans, b_pow(x, 3) + b_pow(max_y - 1, 3));
    }
    std::cout << b_pow(z, 3) - ans << std::endl;
  }

  return 0;
}