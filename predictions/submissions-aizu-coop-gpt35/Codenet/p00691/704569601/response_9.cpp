for (ll x = 1; x * x * x <= z * z * z; x++) {
  ll max_y = cbrt(z * z * z - x * x * x);
  for (ll y = 1; y <= max_y; y++) {
    ans = max(ans, x * x * x + y * y * y);
  }
}