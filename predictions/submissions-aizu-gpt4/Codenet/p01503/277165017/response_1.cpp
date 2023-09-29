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

ll gcd(ll a, ll b) {
  while(b != 0) {
    ll temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
  if(b == 0){
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1, gcd = ext_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return gcd;
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
  int th = t / h;
  for (int i = 0; i < t; i += h) {
    if (s < n) {
      res += max(0, (i - w) / u - l);
      l = i / u;
    }
    s += x;
    if (s >= th)
      s -= th;
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