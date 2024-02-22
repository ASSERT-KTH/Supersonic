#include <iostream>
#include <map>
#include <cmath>
#define MAX_SIZE 140000

typedef long long L;

L P[MAX_SIZE] = {}, E[MAX_SIZE] = {}, Z[MAX_SIZE] = {}, H[MAX_SIZE] = {}, C[MAX_SIZE] = {}, A[MAX_SIZE] = {}, O[MAX_SIZE] = {}, X[MAX_SIZE] = {}, B[MAX_SIZE] = {}, k, n, a, b, c;

std::map<L, L> T[MAX_SIZE];

L M(L f) {
  if (!f)
    return 0;
  return B[f] + M(f & (f - 1));
}

void S(L a, L i) {
  i++;
  L tmp = A[a] + A[P[a]] + C[a];
  for (a = M((tmp % k ? tmp : 0) - M(i)); i < 2e5; i += (i & (-i)))
    B[i] += a;
}

void D(L f) {
  Z[f] = 1;
  for (std::map<L, L>::iterator I = T[f].begin(); I != T[f].end(); ++I) {
    L d = I->first;
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
  L a = X[f];
  L n = X[b];
  if (a != n)
    return M(O[E[a] < E[n] ? (a = n, n = b, b = f, n) : f]) + K(P[a]);
  else
    return abs(M(O[f]) - M(O[b]));
}

int main() {
  std::cin >> n >> k;
  for (L i = 1; i < n; ++i) {
    std::cin >> a >> b >> c;
    T[a][b] = c;
    T[b][a] = c;
  }

  D(a = b = 0);
  for (L i = 1; i <= n; ++i) {
    a = (H[P[i]] != i ? i : 0);
    for (; !b || a; S(a = H[a], O[a] = ++b))
      X[a] = i;
  }
  std::cin >> a;
  for (char s; std::cin >> s >> a >> b; S(H[a], O[a]), S(a, O[a] - 1))
    if (s & 2)
      std::cout << K(a) << std::endl;
    else
      A[a] += b;

  return 0;
}