#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

ll d[15][2005], dp[2005];

int main() {
  int n, K;
  cin >> n >> K;
  vector<int> id, v[2005];
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    id.push_back(b - 1);
    v[b - 1].push_back(a);
  }

  sort(id.begin(), id.end());
  id.erase(unique(id.begin(), id.end()), id.end());

  for (int i = 0; i < id.size(); i++) {
    int j = id[i];
    sort(v[j].begin(), v[j].end(), greater<int>());
  }

  memset(d, 0, sizeof(d));
  for (int i = 0; i < id.size(); i++) {
    int j = id[i];
    for (int k = 1; k <= v[j].size(); k++) {
      d[j][k] += d[j][k - 1] + v[j][k - 1] + (k - 1) * 2;
    }
  }

  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < id.size(); i++) {
    for (int j = K; j >= 0; j--) {
      ll res = dp[j];
      for (int k = 1; k <= v[id[i]].size(); k++) {
        if (j >= k) {
          res = max(res, dp[j - k] + d[id[i]][k]);
        }
      }
      dp[j] = res;
    }
  }

  cout << dp[K] << endl;
  return 0;
}