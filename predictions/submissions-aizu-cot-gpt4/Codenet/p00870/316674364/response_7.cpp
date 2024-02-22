#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;
using ll = long long;
using PI = pair<int, int>;

constexpr double EPS = 1e-6;

template <class T> 
constexpr int SZ(const T& a) {
    return static_cast<int>(a.size());
}

template <typename T, typename U>
ostream &operator<<(ostream &out, const pair<T, U> &val) {
  return out << "(" << val.first << ", " << val.second << ")";
}

template <class T> ostream &operator<<(ostream &out, const vector<T> &val) {
  out << "{";
  for(size_t i = 0; i < val.size(); ++i) 
    out << (i ? ", " : "") << val[i];
  return out << "}";
}

// ... rest of the code remains same ...

void solve() {
  // ... rest of the code remains same ...

  int ans = 0;
  string text;
  for(int jjj = 0; jjj < m; ++jjj) {
    string a;
    cin >> a;
    text += a;
  }

  // ... rest of the code remains same ...

  for(size_t i = 0; i < text.size() + 1; ++i) {
    int cur = i % 250;

    // ... rest of the code remains same ...

    ans += vis[cur][(1 << n) - 1];
    for(size_t i = 0; i < (1 << n); ++i) 
      vis[cur][i] = 0;
    vis[cur][0] = 1;
  }

  // ... rest of the code remains same ...
}

// ... rest of the code remains same ...