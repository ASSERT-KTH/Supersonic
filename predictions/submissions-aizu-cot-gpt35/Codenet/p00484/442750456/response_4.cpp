#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n, K;
  cin >> n >> K;
  vector<int> id;
  vector<vector<int>> v(2005);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    id.push_back(b - 1);
    v[b - 1].push_back(a);
  }

  set<int> idSet(id.begin(), id.end());

  for (int j : idSet) {
    sort(v[j].rbegin(), v[j].rend());
  }

  vector<long long> d(2005), dp(2005);
  vector<pair<int, long long>> p;
  for (int j : idSet) {
    for (int k = 1; k <= v[j].size(); k++) {
      d[k] += d[k - 1] + v[j][k - 1] + (k - 1) * 2;
      p.push_back(make_pair(k, d[k]));
    }
  }

  for (int i = 0; i < idSet.size(); i++) {
    for (int j = 0; j <= K; j++) {
      long long res = dp[j];
      for (int k = 0; k <= v[id[i]].size(); k++) {
        if (j >= k) {
          res = max(res, dp[j - k] + d[k]);
        }
      }
      dp[j] = res;
    }
  }

  cout << dp[idSet.size()] << endl;

  return 0;
}