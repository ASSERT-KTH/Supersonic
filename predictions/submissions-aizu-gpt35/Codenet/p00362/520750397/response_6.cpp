#include <bits/stdc++.h>
#define U [7 << 15] = {}
#define G )+((c=A[a]+A[P[a]]+C[a])%k?c:0)-M(
using namespace std;
typedef long long L;
map<L, L> T U;
L P U, E U, Z U, H U, C U, A U, O U, X U, B U, k, n, a, b, c;
char s U;
L M(L f) { return f ? B[f] + M(f ^ f & -f) : 0; }
L S(L a, L i) {
  for (a = M(i++ G i); i < 2e5; i += i & -i)
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
      if (!H[f] || Z[H[f]] < Z[d]) H[f] = d;
    }
  }
}
L K(L f) {
  a = X[f];
  n = X[b];
  if (a - n) {
    while (E[a] < E[n]) swap(a, n), swap(f, b);
    while (a != n) S(a, O[a]), a = H[a], S(a, O[a] - 1);
    S(a, O[a]), S(b, O[b] - 1);
    return abs(M(O[f]) - M(O[b])) + K(P[b]);
  } else {
    return abs(M(O[f]) - M(O[b]));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (cin >> n >> k; --n; T[a][b] = T[b][a] = c)
    cin >> a >> b >> c;
  for (D(a = b = 0); n < *Z; a = H[P[++n]] - n ? n : 0)
    for (; !b || a; S(a = H[a], O[a] = ++b))
      X[a] = n;
  for (cin >> a; cin >> s >> a >> b; S(H[a], O[a]), S(a, O[a] - 1))
    *s & 2 ? cout << K(a) << endl : A[a] += b;
  return 0;
}