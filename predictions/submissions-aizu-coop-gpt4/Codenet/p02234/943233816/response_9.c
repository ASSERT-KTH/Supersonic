#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

int matrixChainOrder(vector<int>& p) {
  int n = p.size() - 1;
  vector<vector<int>> m(n + 1, vector<int>(n + 1, -1));

  for (int i = 1; i <= n; i++) {
    m[i][i] = 0;
  }

  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;
      m[i][j] = INF;
      for (int k = i; k < j; k++) {
        int q = (m[i][k] == -1 ? matrixChainOrder(p, i, k) : m[i][k]) +
                (m[k + 1][j] == -1 ? matrixChainOrder(p, k + 1, j) : m[k + 1][j]) +
                p[i - 1] * p[k] * p[j];
        if (m[i][j] > q)
          m[i][j] = q;
      }
    }
  }
  return m[1][n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n;
  vector<int> p(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    if (i < n - 1)
      cin >> k;
  }
  
  cin >> p[n];
  int x = matrixChainOrder(p);
  cout << x << "\n";
  return 0;
}