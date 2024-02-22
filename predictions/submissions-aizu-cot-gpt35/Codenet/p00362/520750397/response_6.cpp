#include <iostream>
#include <vector>
using namespace std;

typedef long long L;

vector<vector<L>> T;
vector<L> P, E, Z, H, C, A, O, X, B;
L k, n, a, b, c;

L M(L f) { 
  L res = 0;
  while (f) {
    res += B[f];
    f ^= f & -f;
  }
  return res;
}

void S(L a, L i) {
  for (; i < 2e5; i += i & -i)
    B[i] += a;
}

void D(L f) {
  vector<L> stack;
  stack.push_back(f);
  while (!stack.empty()) {
    L f = stack.back();
    stack.pop_back();
    Z[f] = 1;
    for (L d : T[f]) {
      if (!Z[d]) {
        P[d] = f;
        E[d] = E[f] + 1;
        C[d] = T[f][d];
        stack.push_back(d);
        Z[f] += Z[d];
        if (!H[f] || Z[H[f]] < Z[d])
          H[f] = d;
      }
    }
  }
}

L K(L f) {
  L res = 0;
  while (X[f] != X[b]) {
    a = X[f];
    n = X[b];
    res += M(O[E[a] < E[n] ? a = n, n = b, b = f, n : f]) + K(P[a]);
  }
  res += abs(M(O[f]) - M(O[b]));
  return res;
}

int main() {
  cin >> n >> k;
  T.resize(n + 1);
  P.resize(n + 1);
  E.resize(n + 1);
  Z.resize(n + 1);
  H.resize(n + 1);
  C.resize(n + 1);
  A.resize(n + 1);
  O.resize(n + 1);
  X.resize(n + 1);
  B.resize(2e5 + 1);
  for (int i = 1; i < n; i++) {
    cin >> a >> b >> c;
    T[a].push_back(b);
    T[b].push_back(a);
    C[a] = C[b] = c;
  }
  D(1);
  while (cin >> a) {
    if (cin.peek() == ' ') {
      char s;
      cin >> s >> a >> b;
      S(H[a], O[a]);
      S(a, O[a] - 1);
      if (s & 2)
        cout << K(a) << endl;
      else
        A[a] += b;
    }
  }
  return 0;
}