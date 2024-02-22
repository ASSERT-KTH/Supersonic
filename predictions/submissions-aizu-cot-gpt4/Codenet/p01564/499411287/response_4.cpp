#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
// ...
// (Rest of the code is the same)
// ...
inline void putint(int d) {
  static char buf[10];
  int c = 0;
  bool neg = false;
  if (d < 0) {
    putchar_unlocked('-');
    d *= -1;
  }
  if (!d) {
    putchar_unlocked('0');
    return;
  }
  while (d) {
    buf[c++] = d % 10;
    d /= 10;
  }
  while (--c) {
    putchar_unlocked(buf[c] + '0');
  }
}
int main2() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n, q;
  n = getint();
  q = getint();
  for (int i = 0; i < n; ++i) {
    int w;
    w = getint();
    hl.data[i] = w;
  }
  for (int i = 0; i < n - 1; ++i) {
    int s, e;
    s = getint();
    e = getint();
    --s;
    --e;
    hl.add(s, e);
  }
  hl.init();
  for (int i = 0; i < q; ++i) {
    int t, a, b, c;
    t = getint();
    a = getint();
    b = getint();
    c = getint();
    --a;
    --b;
    if (t == 1) {
      hl.path_set(a, b, c);
    } else {
      auto n = hl.path_get(a, b);
      putint((n.mv < 0) ? n.mv : n.ma);
      putchar_unlocked('\n');
    }
  }
  return 0;
}
signed main() {
#ifndef __APPLE__
  static ll eord, enew;
  const int sz = 32 * 1024 * 1024;
  static void *p = malloc(sz);
  enew = (long long)p + sz - 1;
  __asm__ volatile("mov %%rsp, %0" : "=r"(eord));
  __asm__ volatile("mov %0, %%rsp" : : "r"(enew));
#endif
  main2();
#ifndef __APPLE__
  __asm__ volatile("mov %0, %%rsp" : : "r"(eord));
#endif
  return 0;
}