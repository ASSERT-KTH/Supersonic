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

mat mul(const mat &A, const mat &B) {
  int n = A.size();
  mat C(n, vl(n));
  rep(i, n) rep(j, n) {
    ll temp = 0;  // Temporary variable to store multiplication result
    rep(k, n) {
      ll a = A[i][k];  // Store result in a variable
      ll b = B[k][j];  // Store result in a variable
      temp += a * b;
    }
    C[i][j] = temp % mod;  // Apply modulo operation once
  }
  return C;
}

// The rest of the code remains the same as before...

unordered_map<ll, vector<int>> obj; // Use unordered_map instead of map

int main() {
  ios_base::sync_with_stdio(false);  // Disable synchronization with C's stdio
  cin.tie(NULL);  // Untie cin and cout streams

  // The rest of the code remains the same as before...
}