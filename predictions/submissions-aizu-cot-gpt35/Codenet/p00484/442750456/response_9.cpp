#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main() {
  int n, K;
  cin >> n >> K;
  vector<vector<int>> v(K);
  vector<int> id;
  
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

  vector<P> p;
  
  for (int i = 0; i < id.size(); i++) {
    int j = id[i];
    for (int k = 1; k <= v[j].size(); k++) {
      v[j][k - 1] += v[j][k - 2] + (k - 1) * 2;
      p.push_back(make_pair(k, v[j][k - 1]));
    }
  }

  vector<vector<ll>> dp(id.size() + 1, vector<ll>(K + 1, 0));
  
  for (int i = 0; i < id.size(); i++) {
    for (int j = 0; j <= K; j++) {
      ll res = dp[i][j];
      for (int k = 0; k <= v[id[i]].size(); k++) {
        if (j >= k) {
          res = max(res, dp[i][j - k] + v[id[i]][k]);
        }
      }
      dp[i + 1][j] = res;
    }
  }

  cout << dp[id.size()][K] << endl;
  return 0;
}