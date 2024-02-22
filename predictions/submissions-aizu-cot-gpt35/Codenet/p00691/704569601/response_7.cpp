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
    ll ans = 0;
    ll limit = b_pow(z, 2) * z;
    for (ll x = 1; x * x * x <= limit; x++) {
      ll limit_y = limit - x * x * x;
      for (ll y = 1; y * y * y <= limit_y; y++) {
        ans = std::max(ans, x * x * x + y * y * y);
      }
    }
    std::cout << b_pow(z, 3) - ans << std::endl;
  }
}