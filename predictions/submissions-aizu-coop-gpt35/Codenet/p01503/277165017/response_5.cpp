ll ext_gcd(ll a, ll b, ll &x, ll &y) {
  ll old_x = 1, x = 0;
  ll old_y = 0, y = 1;
  while (b) {
    ll quotient = a / b;
    ll temp = b;
    b = a % b;
    a = temp;
    temp = old_x;
    old_x = x;
    x = temp - quotient * x;
    temp = old_y;
    old_y = y;
    y = temp - quotient * y;
  }
  return a;
}