#include <bits/stdc++.h>

#define SIZE 200000

typedef long long L;
using namespace std;

vector<tuple<L, L, L>> T[SIZE];
L P[SIZE] = {}, E[SIZE] = {}, Z[SIZE] = {}, H[SIZE] = {}, C[SIZE] = {}, A[SIZE] = {}, O[SIZE] = {}, X[SIZE] = {}, B[SIZE] = {}, k, n, a, b, c;
char s[SIZE] = {};

L M(L f) { return f ? B[f] + M(f & (f - 1)) : 0; }

void S(L a, L i) {
  for (a = M(++i); i < SIZE; i += i & -i)
    B[i] += a;
}

void D(L f) {
  L d;
  Z[f] = 1;
  for (auto I = T[f].begin(); I != T[f].end(); I++)
    d = get<0>(*I), Z[d] || (P[d] = f, E[d] = E[f] + 1, C[d] = get<1>(*I), D(d),
    Z[f] += Z[d], H[f] = (!H[f] | Z[H[f]] < Z[d]) ? d : H[f]);
}

L K(L f) {
  a = X[f];
  n = X[b];
  return a - n ? M(O[E[a] < E[n] ? a = n, n = b, b = f, n : f]) + K(P[a])
               : abs(M(O[f]) - M(O[b]));
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n >> k;
  while (--n)
    cin >> a >> b >> c, T[a].push_back(make_tuple(b, c, 0)), T[b].push_back(make_tuple(a, c, 0));
  for (D(a = b = 0); n < Z[0]; ++n, a = H[P[n]] - n ? n : 0)
    for (; !b | a; S(a = H[a], O[a] = ++b))
      X[a] = n;
  for (cin >> a; cin >> s >> a >> b; S(H[a], O[a]), S(a, O[a] - 1))
    s[0] == '2' ? cout << K(a) << '\n', 0 : A[a] += b;
  return 0;
}