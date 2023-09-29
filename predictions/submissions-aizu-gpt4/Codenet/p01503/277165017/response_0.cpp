#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int MN = 501 * 1000 * 1000;
ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}
ll ext_gcd(ll a, ll b, ll &x, ll &y) {
  if(!b){
    x = 1;
    y = 0;
    return a;
  }
  ll d = ext_gcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
int w, d, n, m, t, u, h;
int x, tu, th;
void init() {
  m = t - m % t;
  u = gcd(t, w + d), h = gcd(t, m);
  tu = t / u;
  th = t / h;
  ll xx, y;
  ext_gcd(m, t, xx, y);
  x = ((xx % th) + th) % th;
}
int solve() {
  init();
  int res = 0;
  int l = 0;
  int s = 0;
  for (int i = 0; i < t; i += h) {
    if (s < n) {
      res += max(0, (i - w) / u - l);
      l = i / u;
    }
    s += x;
    s %= th;
  }
  res += max(0, (t - w) / u - l);
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> w >> d >> n >> m >> t;
  w++;
  d--;
  printf("%.20f\n", 1.0 * solve() / tu);
  return 0;
}