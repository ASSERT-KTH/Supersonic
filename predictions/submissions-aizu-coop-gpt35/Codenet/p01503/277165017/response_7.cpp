#include <iostream>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const int MN = 501 * 1000 * 1000;

ll gcd(ll a, ll b) {
  if (!a)
    return b;
  return gcd(b % a, a);
}

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
  ll d = a;
  if (b) {
    d = ext_gcd(b, a % b, y, x);
    y -= a / b * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}

int w, d, n, m, t, u, h;
int x, tu, th;

void init() {
  m = t - m % t;
  u = gcd(t, w + d);
  h = gcd(t, m);
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
  int resDiff = max(0, (t - w) / u - l);
  for (int i = 0; i < t; i += h) {
    res += resDiff;
    l = i / u;
    s += x;
    if (s >= th)
      s -= th;
    if (s < n)
      resDiff = max(0, (i - w) / u - l);
    else
      resDiff = 0;
  }
  res += resDiff;
  return res;
}

int main() {
  cin >> w >> d >> n >> m >> t;
  w++;
  d--;
  cout << fixed << setprecision(20) << 1.0 * solve() / tu << endl;
  return 0;
}