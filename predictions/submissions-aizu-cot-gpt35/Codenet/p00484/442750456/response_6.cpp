#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

ll dp[2005][2005];

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
  
  vector<P> p;
  p.reserve(n);
  
  for (int i = 0; i < id.size(); i++) {
    int j = id[i];
    for (int k = 1; k <= v[j].size(); k++) {
      dp[j][k] += dp[j][k - 1] + v[j][k - 1] + (k - 1) * 2;
      p.push_back(make_pair(k, dp[j][k]));
    }
  }
  
  for (int i = 0; i < id.size(); i++) {
    for (int j = 0; j <= K; j++) {
      ll res = dp[i][j];
      for (int k = 0; k <= v[id[i]].size(); k++) {
        if (j >= k) {
          res = max(res, dp[i][j - k] + dp[id[i]][k]);
        }
      }
      dp[i + 1][j] = res;
    }
  }
  
  cout << dp[id.size()][K] << endl;
  return 0;
}