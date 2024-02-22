#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_N = 2e5 + 1;
vector<pair<int, int>> graph[MAX_N];
vector<int> P(MAX_N), E(MAX_N), C(MAX_N), O(MAX_N), X(MAX_N), B(MAX_N), Z(MAX_N), H(MAX_N), A(MAX_N);
int k, n, a, b;

int M(int f) {
  return f ? B[f] + M(f ^ f & -f) : 0;
}

void S(int a, int i) {
  for (; i < MAX_N; i += i & -i)
    B[i] += a;
}

void dfs(int f) {
  Z[f] = 1;
  for (auto& p : graph[f]) {
    int d = p.first;
    if (!Z[d]) {
      P[d] = f;
      E[d] = E[f] + 1;
      C[d] = p.second;
      dfs(d);
      Z[f] += Z[d];
      if (!H[f] || Z[H[f]] < Z[d]) {
        H[f] = d;
      }
    }
  }
}

int calculate(int f) {
  a = X[f];
  b = X[b];
  return a - b ? M(O[E[a] < E[b] ? a = b, b = f, b : f]) + calculate(P[a]) : abs(M(O[f]) - M(O[b]));
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  dfs(0);

  int q;
  cin >> q;
  while (q--) {
    char s;
    cin >> s >> a >> b;
    if (s == '1') {
      cout << calculate(a) << endl;
    } else {
      S(H[a], O[a]);
      S(a, O[a] - 1);
      A[a] += b;
    }
  }

  return 0;
}