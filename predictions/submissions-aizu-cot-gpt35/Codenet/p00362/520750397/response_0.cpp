#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 1;
vector<int> T(MAXN * MAXN);
vector<int> P(MAXN), E(MAXN), Z(MAXN), H(MAXN), C(MAXN), A(MAXN), O(MAXN), X(MAXN), B(MAXN);
int k, n, a, b, c;

int sum(int f) {
  int res = 0;
  while (f) {
    res += B[f];
    f ^= f & -f;
  }
  return res;
}

void add(int f, int val) {
  while (f < MAXN) {
    B[f] += val;
    f += f & -f;
  }
}

void dfs(int f) {
  Z[f] = 1;
  for (int i = 0; i < n; i++) {
    int d = i;
    if (!Z[d]) {
      P[d] = f;
      E[d] = E[f] + 1;
      C[d] = T[f * MAXN + d];
      dfs(d);
      Z[f] += Z[d];
      if (!H[f] || Z[H[f]] < Z[d]) {
        H[f] = d;
      }
    }
  }
}

int query(int f) {
  int a = X[f];
  int b = X[0];
  if (a != b) {
    int res = 0;
    while (O[a] != O[b]) {
      if (E[a] < E[b]) {
        swap(a, b);
      }
      res += sum(O[a]) - sum(O[P[a]]) + (C[a] % k ? C[a] : 0) - sum(O[P[a]]);
      a = P[a];
    }
    res += abs(sum(O[f]) - sum(O[b]));
    return res;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b >> c;
    T[a * MAXN + b] = c;
    T[b * MAXN + a] = c;
  }

  dfs(0);

  int q;
  char s;
  cin >> q;
  while (q--) {
    cin >> s >> a >> b;
    if (s & 2) {
      printf("%d\n", query(a));
    } else {
      add(O[a], b);
    }
  }

  return 0;
}