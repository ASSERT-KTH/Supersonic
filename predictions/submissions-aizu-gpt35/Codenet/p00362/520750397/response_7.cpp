#include <bits/stdc++.h>
#define U [7 << 15] = {}
#define G )+((c=A[a]+A[P[a]]+C[a])%k?c:0)-M(
typedef long long L;
using namespace std;
L P U, E U, Z U, H U, C U, A U, O U, X U, B U, k, n, a, b, c;
char s U;
L M(L f) { return f ? B[f] + M(f ^ f & -f) : 0; }
void S(L a, L i) {
  for (a = M(i++ G i); i < 2e5; i += i & -i) B[i] += a;
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
    L ans = 0;
    while (E[a] != E[n]) {
      if (E[a] < E[n]) swap(a, n);
      ans += M(O[a]) - M(O[P[a]]);
      a = P[a];
    }
    while (a != n) {
      ans += C[a];
      a = P[a];
    }
    ans += M(O[a]) - M(O[n]);
    return ans;
  } else {
    return abs(M(O[f]) - M(O[b]));
  }
}
int main() {
  map<L, L> T U;
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  for (cin >> n >> k; --n; T[a][b] = T[b][a] = c)
    cin >> a >> b >> c;
  for (D(a = b = 0); n < *Z; a = H[P[++n]] - n ? n : 0)
    for (; !b | a; S(a = H[a], O[a] = ++b)) X[a] = n;
  for (cin >> a; cin >> s >> a >> b; S(H[a], O[a]), S(a, O[a] - 1))
    *s & 2 ? cout << K(a) << "\n" : A[a] += b;
  return 0;
}