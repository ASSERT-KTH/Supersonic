#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main() {
  int n, K;
  cin >> n >> K;
  vector<int> id;
  vector<vector<int>> v(K);
  id.reserve(n);
  
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    id.emplace_back(b - 1);
    v[b - 1].emplace_back(a);
  }
  
  sort(id.begin(), id.end());
  
  vector<P> p;
  for (int i = 0; i < id.size(); i++) {
    int j = id[i];
    sort(v[j].rbegin(), v[j].rend());
    
    ll sum = 0;
    for (int k = 0; k < v[j].size(); k++) {
      sum += v[j][k] + 2 * k;
      p.emplace_back(k + 1, sum);
    }
  }
  
  vector<vector<ll>> dp(id.size() + 1, vector<ll>(K + 1, 0));
  
  for (int i = 0; i < id.size(); i++) {
    for (int j = 0; j <= K; j++) {
      ll res = dp[i][j];
      for (int k = 0; k <= v[id[i]].size(); k++) {
        if (j >= k) {
          res = max(res, dp[i][j - k] + p[k].second);
        }
      }
      dp[i + 1][j] = res;
    }
  }
  
  cout << dp[id.size()][K] << endl;
  
  return 0;
}