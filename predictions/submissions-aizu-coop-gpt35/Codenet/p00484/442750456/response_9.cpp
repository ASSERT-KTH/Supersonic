#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main() {
  int n, K;
  cin >> n >> K;

  vector<int> id;
  vector<vector<int>> v(K);

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    id.push_back(b - 1);
    v[b - 1].push_back(a);
  }

  sort(id.begin(), id.end());
  id.erase(unique(id.begin(), id.end()), id.end());

  for (int i = 0; i < id.size(); i++) {
    sort(v[id[i]].begin(), v[id[i]].end(), greater<int>());
  }

  vector<vector<ll>> d(K, vector<ll>(2005, 0));
  vector<P> p;

  for (int i = 0; i < id.size(); i++) {
    int j = id[i];
    for (int k = 1; k <= v[j].size(); k++) {
      d[j][k] += d[j][k - 1] + v[j][k - 1] + (k - 1) * 2;
      p.emplace_back(k, d[j][k]);
    }
  }

  sort(p.begin(), p.end(), [](const P& a, const P& b) {
    return a.first < b.first;
  });

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