#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <random>
#include <unordered_map>
#include <vector>

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
int l, s;

void init() {
  m = t - m; // removed mod operation
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
  l = 0;
  s = 0;
  th = t / h;
  float u_reciprocal = 1.0 / u;  // calculated reciprocal of u
  for (int iterationCount = 0; iterationCount < t; iterationCount++) {
    int i = h * iterationCount; // calculate value of i
    if (s < n) {
      res += max(0, (int)((i - w) * u_reciprocal) - l); // replaced division with multiplication
      l = i * u_reciprocal; // replaced division with multiplication
    }
    s += x;
    if (s >= th)
      s -= th;
  }
  res += max(0, (int)((t - w) * u_reciprocal) - l); // replaced division with multiplication
  return res;
}

int main() {
  cin >> w >> d >> n >> m >> t;
  w++;
  d--;
  printf("%.20f\n", 1.0 * solve() / tu);
  return 0;
}