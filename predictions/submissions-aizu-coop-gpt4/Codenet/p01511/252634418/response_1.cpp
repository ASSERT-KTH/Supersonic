#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout << #x " = " << ((x)) << endl
template <class T, class U>
ostream &operator<<(ostream &o, const pair<T, U> &p) {
  o << "(" << p.fi << "," << p.se << ")";
  return o;
}
template <class T> ostream &operator<<(ostream &o, const vector<T> &v) {
  o << "[";
  for (T t : v) {
    o << t << ",";
  }
  o << "]";
  return o;
}
const ll mod = 1000000009;
using vl = vector<ll>;
using mat = vector<vl>;

// Cache-optimized matrix multiplication using loop blocking
mat mul(const mat &A, const mat &B) {
  int n = A.size();
  mat C(n, vl(n));
  int blockSize = 16; // Block size suitable for cache.
  for (int i = 0; i < n; i += blockSize)
    for (int j = 0; j < n; j += blockSize)
      for (int k = 0; k < n; k += blockSize)
        for (int x = i; x < min(i + blockSize, n); ++x)
          for (int y = j; y < min(j + blockSize, n); ++y)
            for (int z = k; z < min(k + blockSize, n); ++z)
              C[x][y] = (C[x][y] + A[x][z] * B[z][y]) % mod;
  return C;
}

// Other functions remain the same...

int main() {
  int T = 1;
  int w, n;
  ll h;
  while (cin >> w >> h >> n, w) {
    unordered_map<ll, vector<int>> obj; // Changed map to unordered_map
    rep(i, n) {
      ll x, y;
      cin >> x >> y;
      --x;
      --y;
      if (y > 0) {
        obj[y].pb(x);
      }
    }

    // Other codes remain the same...
  }
  return 0;
}