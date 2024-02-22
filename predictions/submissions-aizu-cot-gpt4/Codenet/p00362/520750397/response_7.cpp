#include <unordered_map>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long L;

unordered_map<L, L> T[7 << 15];
L P[7 << 15] = {}, E[7 << 15] = {}, Z[7 << 15] = {}, H[7 << 15] = {}, C[7 << 15] = {}, A[7 << 15] = {}, O[7 << 15] = {}, X[7 << 15] = {}, B[7 << 15] = {}, k, n, a, b, c;
char s[7 << 15] = {};

L M(L f) {
  L res = 0;
  while (f) {
    res += B[f];
    f ^= f & -f;
  }
  return res;
}

L S(L a, L i) {
  a = M(i++ + ((c = A[a] + A[P[a]] + C[a]) % k ? c : 0) - M(i));
  for (; i < 2e5; i += i & -i)
    B[i] += a;
}

L D(L f) {
  L d;
  Z[f] = 1;
  for (auto I = T[f].begin(); I != T[f].end(); I++) {
    d = I->first;
    if (!Z[d]) {
      P[d] = f;
      E[d] = E[f] + 1;
      C[d] = I->second;
      D(d);
      Z[f] += Z[d];
      if (!H[f] | Z[H[f]] < Z[d]) 
        H[f] = d;
    }
  }
}

L K(L f) {
  a = X[f];
  n = X[b];
  return a != n ? M(O[E[a] < E[n] ? (a = n, n = b, b = f, n) : f] + ((c = A[a] + A[P[a]] + C[a]) % k ? c : 0) - M(O[a])) + K(P[a])
               : abs(M(O[f]) - M(O[b]));
}

int main() {
  scanf("%lld %lld", &n, &k);
  while (--n) {
    scanf("%lld %lld %lld", &a, &b, &c);
    T[a][b] = T[b][a] = c;
  }
  for (D(a = b = 0); n < *Z; a = H[P[++n]] - n ? n : 0)
    for (; !b || a; S(a = H[a], O[a] = ++b))
      X[a] = n;
  scanf("%lld", &a);
  while (scanf("%s %lld %lld", s, &a, &b) != EOF) {
    S(H[a], O[a]); 
    S(a, O[a] - 1);
    if (*s & 2) {
      printf("%lld\n", K(a));
    } else {
      A[a] += b;
    }
  }
  return 0;
}