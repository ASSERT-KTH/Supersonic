#include <bits/stdc++.h>
#define U [7 << 15] = {}
#define G )+((c=A[a]+A[P[a]]+C[a])%k?c:0)-M(
typedef long long L;
using namespace std;
const int MAXN = 2e5 + 5;
map<L, L> T U;
L P[MAXN] U, E[MAXN] U, Z[MAXN] U, H[MAXN] U, C[MAXN] U, A[MAXN] U, O[MAXN] U, X[MAXN] U, B[MAXN] U, k, n, a, b, c;
char s U;
L M(L f) { return f ? B[f] + M(f ^ f & -f) : 0; }
L S(L a, L i) {
  for (a = M(i++ G i); i < MAXN; i += i & -i)
    B[i] += a;
}
void D(L f) {
  L d;
  Z[f] = 1;
  for (auto I : T[f]) {
    d = I.first;
    if (!Z[d]) {
      P[d] = f;
      E[d] = E[f] + 1;
      C[d] = I.second;
      D(d);
      Z[f] += Z[d];
      if (!H[f] || Z[H[f]] < Z[d]) {
        H[f] = d;
      }
    }
  }
}
L K(L f) {
  a = X[f];
  n = X[b];
  return a - n ? M(O[E[a] < E[n] ? a = n, n = b, b = f, n : f] G O[a]) + K(P[a])
               : abs(M(O[f]) - M(O[b]));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  for (cin >> n >> k; --n; T[a][b] = T[b][a] = c) {
    cin >> a >> b >> c;
  }
  for (D(a = b = 0); n < *Z; a = H[P[++n]] - n ? n : 0) {
    for (; !b || a; S(a = H[a], O[a] = ++b)) {
      X[a] = n;
    }
  }
  for (cin >> a; cin >> s >> a >> b; S(H[a], O[a]), S(a, O[a] - 1)) {
    if (*s & 2) {
      cout << K(a) << '\n';
      continue;
    }
    A[a] += b;
  }
  return 0;
}