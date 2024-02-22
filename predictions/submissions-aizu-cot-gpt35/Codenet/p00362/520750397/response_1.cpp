#include <iostream>
#include <map>
using namespace std;

const int MAXN = 7 << 15;
typedef long long L;

map<L, L> T;
L P[MAXN], E[MAXN], Z[MAXN], H[MAXN], C[MAXN], A[MAXN], O[MAXN], X[MAXN], B[MAXN];
L k, n, a, b;

L M(L f) {
  return f ? B[f] + M(f ^ f & -f) : 0;
}

void S(L a, L i) {
  for (a = M(i++ G i); i < 2e5; i += i & -i)
    B[i] += a;
}

void D(L f) {
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
  cin >> n >> k;
  for (--n; n; T[a][b] = T[b][a] = c) {
    cin >> a >> b >> c;
  }
  for (D(a = b = 0); n < *Z; a = H[P[++n]]) {
    for (; !b || a; S(a = H[a], O[a] = ++b)) {
      X[a] = n;
    }
  }
  while (cin >> a) {
    char s;
    cin >> s >> a >> b;
    S(H[a], O[a]);
    S(a, O[a] - 1);
    if (*s & 2) {
      cout << K(a) << endl;
    } else {
      A[a] += b;
    }
  }

  return 0;
}