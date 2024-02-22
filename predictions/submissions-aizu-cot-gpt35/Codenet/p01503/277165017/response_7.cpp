#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

int w, d, n, m, t;
int tu, th;

int solve() {
  m = t - m % t;
  int u = __gcd(t, w + d);
  int h = __gcd(t, m);
  tu = t / u;
  th = t / h;

  ll xx, y;
  ll d = m;
  if (t) {
    d = __gcd(m, t);
    if (d != 1) {
      xx = 0;
      y = 0;
    } else {
      xx = 1;
      y = 0;
    }
  } else {
    xx = 1;
    y = 0;
  }

  int res = 0;
  int l = 0;
  int s = 0;
  for (int i = 0; i < t; i += h) {
    if (s < n) {
      res += max(0, (i - w) / u - l);
      l = i / u;
    }
    s += ((xx % th) + th) % th;
    if (s >= th)
      s -= th;
  }
  res += max(0, (t - w) / u - l);
  return res;
}

int main() {
  cin >> w >> d >> n >> m >> t;
  w++;
  d--;
  printf("%.20f\n", 1.0 * solve() / tu);
  return 0;
}