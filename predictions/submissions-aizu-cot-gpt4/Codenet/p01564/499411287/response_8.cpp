#pragma GCC optimize("Ofast")
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
struct Tree;
struct Node;
typedef Tree* NP;
...
// Rest of the code remains the same
...
inline int getint() {
  char c;
  int res = 0;
  bool neg = false;
  while (true) {
    c = getchar_unlocked();
    if (c == '-') {
      neg = true;
      break;
    }
    if ('0' <= c && c <= '9') {
      res = (c - '0');
      break;
    }
  }
  while (c = getchar_unlocked(), '0' <= c && c <= '9') {
    res <<= 1; // multiply by 2
    res += (c - '0');
  }
  if (neg)
    res = ~res + 1; // multiply by -1
  return res;
}
inline void putint(int d) {
  static char buf[10];
  int c = 0;
  bool neg = false;
  if (d < 0) {
    putchar_unlocked('-');
    d = ~d + 1; // multiply by -1
  }
  if (!d) {
    putchar_unlocked('0');
    return;
  }
  while (d) {
    buf[c++] = (d & 1); // get remainder of division by 2
    d >>= 1; // divide by 2
  }
  while (c--) {
    putchar_unlocked(buf[c] + '0');
  }
}
...
// Rest of the code remains the same
...