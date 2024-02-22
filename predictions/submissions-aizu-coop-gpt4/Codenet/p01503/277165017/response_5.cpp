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
map<pair<ll, ll>, ll> gcd_map; // To store already computed gcds

inline ll gcd(ll a, ll b) {
  if (gcd_map.find({a, b}) != gcd_map.end()) // Check if gcd is already computed
    return gcd_map[{a, b}];

  ll res;
  if (!a)
    res =  b;
  else
    res = gcd(b % a, a);

  gcd_map[{a, b}] = res; // Store computed gcd
  return res;
}

inline ll ext_gcd(ll a, ll b, ll &x, ll &y) {
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
  int th = t / h;
  double reciprocal_u = 1.0 / u; // compute reciprocal once
  for (int i = 0; i < t; i += h) {
    if (s < n) {
      res += max(0, int((i - w) * reciprocal_u) - l); // use multiplication instead of division
      l = i * reciprocal_u;
    }
    s += x;
    if (s >= th)
      s -= th;
  }
  res += max(0, int((t - w) * reciprocal_u) - l);
  return res;
}

int main() {
  scanf("%d%d%d%d%d", &w, &d, &n, &m, &t); // replace cin with scanf
  w++;
  d--;
  printf("%.20f\n", 1.0 * solve() / tu); // replace cout with printf
  return 0;
}