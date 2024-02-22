#include <bits/stdc++.h>
#define U [7 << 15] = {}
using namespace std;
typedef long long L;
unordered_map<L, L> T U;
L P U, E U, Z U, H U, C U, A U, O U, X U, B U, k, n, a, b, c;
char s U;

L M(L f) { return f ? B[f] + M(f - 1) : 0; }

L S(L a, L i) {
  for (a = M(i++); i < 2e5; i++)
    B[i] += a;
}

L D(L f) {
  L d;
  Z[f] = 1;
  for (auto I = T[f].begin(); I != T[f].end(); I++)
    d = I->first, !Z[d] ? P[d] = f, E[d] = E[f] + 1, C[d] = I->second, D(d),
    Z[f] += Z[d], !H[f] || Z[H[f]] < Z[d] ? H[f] = d : 0 : 0;
}

L K(L f) {
  a = X[f];
  n = X[b];
  return a - n ? M(O[E[a] < E[n] ? a = n, n = b, b = f, n : f]) + K(P[a])
               : abs(M(O[f]) - M(O[b]));
}

int main() {
  for (cin >> n >> k; --n; T[a][b] = T[b][a] = c)
    cin >> a >> b >> c;
  for (D(a = b = 0); n < *Z; a = H[P[++n]] - n ? n : 0)
    for (; !b || a; S(a = H[a], O[a] = ++b))
      X[a] = n;
  for (cin >> a; cin >> s >> a >> b; S(H[a], O[a]), S(a, O[a] - 1))
    s[0] == '2' ? cout << K(a) << endl : A[a] += b;
  return 0;
}