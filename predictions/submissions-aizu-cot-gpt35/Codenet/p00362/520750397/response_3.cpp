#include <iostream>
#include <vector>
using namespace std;

typedef long long L;

vector<vector<pair<L, L>>> T;
vector<bool> Z;
vector<L> H, C, A, O, X, P, E, B;
L k, n, a, b, c;

L M(L f) {
  return f ? B[f] + M(f ^ f & -f) : 0;
}

void S(L a, L i) {
  for (a = M(i++ + ((c = A[a] + A[P[a]] + C[a]) % k ? c : 0) - M(a)); i < 2e5; i += i & -i)
    B[i] += a;
}

void D(L f) {
  L d;
  Z[f] = true;
  for (auto I = T[f].begin(); I != T[f].end(); I++) {
    d = I->first;
    if (!Z[d]) {
      P[d] = f;
      E[d] = E[f] + 1;
      C[d] = I->second;
      D(d);
      Z[f] += Z[d];
      if (!H[f] || Z[H[f]] < Z[d])
        H[f] = d;
    }
  }
}

L K(L f) {
  a = X[f];
  n = X[b];
  return a - n ? M(O[E[a] < E[n] ? a = n, n = b, b = f, n : f]) + K(P[a]) : abs(M(O[f]) - M(O[b]));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> k;
  
  T.resize(n + 1);
  Z.resize(n + 1);
  H.resize(n + 1);
  C.resize(n + 1);
  A.resize(n + 1);
  O.resize(n + 1);
  X.resize(n + 1);
  P.resize(n + 1);
  E.resize(n + 1);
  B.resize(2e5 + 1);
  
  while (--n) {
    cin >> a >> b >> c;
    T[a].push_back({b, c});
    T[b].push_back({a, c});
  }
  
  D(a = b = 0);
  
  for (; n < *Z.begin(); a = H[P[++n]])
    for (; !b || a; S(a = H[a], O[a] = ++b))
      X[a] = n;
  
  while (cin >> a) {
    char s;
    cin >> s >> a >> b;
    S(H[a], O[a]);
    S(a, O[a] - 1);
    if (s & 2)
      cout << K(a) << endl;
    else
      A[a] += b;
  }
  
  return 0;
}