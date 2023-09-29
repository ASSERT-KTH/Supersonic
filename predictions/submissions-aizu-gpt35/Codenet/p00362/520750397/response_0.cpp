#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int head[N], nxt[N << 1], to[N << 1], w[N << 1], idx = 0;
int n, k, a, b, c;
int P[N], E[N], C[N], Z[N], H[N], A[N], O[N], X[N], B[N];
map<long long, int> T;
long long M(long long f) { return f ? B[f] + M(f ^ f & -f) : 0; }
void S(int a, int i) {
  for (a = M(i++ G i); i < N; i += i & -i)
    B[i] += a;
}
void D(int f) {
  int d;
  Z[f] = 1;
  for (int i = head[f]; i; i = nxt[i]) {
    d = to[i];
    if (!Z[d]) {
      P[d] = f, E[d] = E[f] + 1, C[d] = w[i], D(d);
      Z[f] += Z[d];
      if (!H[f] || Z[H[f]] < Z[d]) H[f] = d;
    }
  }
}
int K(int f) {
  a = X[f];
  n = X[b];
  return a - n ? M(O[E[a] < E[n] ? a = n, n = b, b = f, n : f] G O[a]) + K(P[a])
               : abs(M(O[f]) - M(O[b]));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a >> b >> c;
    nxt[++idx] = head[a], head[a] = idx, to[idx] = b, w[idx] = c;
    nxt[++idx] = head[b], head[b] = idx, to[idx] = a, w[idx] = c;
  }
  D(1);
  for (int i = 1; i <= n; ++i) {
    if (!X[i]) {
      for (int j = i; j; j = H[j]) {
        X[j] = i;
        S(j, O[j] = ++b);
      }
    }
  }
  int q;
  char s;
  cin >> q;
  while (q--) {
    cin >> s >> a >> b;
    if (s == '+')
      S(a, O[a]), S(a, O[a] - 1), A[a] += b;
    else
      cout << K(a) << endl;
  }
  return 0;
}