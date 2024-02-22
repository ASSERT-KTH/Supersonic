#include <bits/stdc++.h>
#define MAX_N 200000

typedef long long ll;

using namespace std;

bitset<MAX_N> Z;
ll P[MAX_N], E[MAX_N], H[MAX_N], C[MAX_N], A[MAX_N], O[MAX_N], X[MAX_N], B[MAX_N], k, n, a, b, c;
vector<pair<ll,ll>> T[MAX_N];
char s[MAX_N];

inline ll M(ll f) { return f ? B[f] + M(f ^ f & -f) : 0; }

void S(ll a, ll i) {
  for (a = M(i++); i < MAX_N; i += i & -i)
    B[i] += a;
}

void D(ll f) {
  ll d;
  Z[f] = 1;
  for (auto I = T[f].begin(); I != T[f].end(); I++)
    if (d = I->first, !Z[d])
      P[d] = f, E[d] = E[f] + 1, C[d] = I->second, D(d),
      Z[f] += Z[d], !H[f] | Z[H[f]] < Z[d] ? H[f] = d : 0;
}

ll K(ll f) {
  a = X[f];
  n = X[b];
  return a - n ? M(O[E[a] < E[n] ? a = n, n = b, b = f, n : f]) + K(P[a])
               : abs(M(O[f]) - M(O[b]));
}

int main() {
  scanf("%lld %lld", &n, &k);
  while (--n) {
    scanf("%lld %lld %lld", &a, &b, &c);
    T[a].push_back({b,c});
    T[b].push_back({a,c});
  }
  for (D(a = b = 0); n < Z.count(); a = H[P[++n]] - n ? n : 0)
    for (; !b | a; S(a = H[a], O[a] = ++b))
      X[a] = n;
  scanf("%lld", &a);
  while (scanf("%s %lld %lld", s, &a, &b) != EOF) {
    S(H[a], O[a]), S(a, O[a] - 1);
    if(*s & 2)
      printf("%lld\n", K(a));
    else
      A[a] += b;
  }
  return 0;
}