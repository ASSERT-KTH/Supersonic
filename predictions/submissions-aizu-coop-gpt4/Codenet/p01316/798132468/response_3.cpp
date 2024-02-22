#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 100000000;

int main() {
  int n, m;
  while (cin >> n >> m, n) {
    vector<int> b(m);
    for (int i = 0; i < m; i++)
      cin >> b[i];
      
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++)
      cin >> a[i + 1];

    vector<vector<int>> dp(n + 1, vector<int>(256, INF));
    dp[0][128] = 1;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < 256; j++)
        if (dp[i][j] != INF)
          for (int k = 0; k < m; k++) {
            int p = j + b[k];
            p = min(max(p, 0), 255);
            dp[i + 1][p] = min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
          }

    int p = INF;
    p = *min_element(dp[n].begin(), dp[n].end());
    cout << p - 1 << endl;
  }
  return 0;
}