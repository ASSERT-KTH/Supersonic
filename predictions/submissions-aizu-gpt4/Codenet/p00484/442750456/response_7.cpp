#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define MAXN 2010
#define P pair<int, int>
using namespace std;

ll d[MAXN][MAXN], dp[MAXN][MAXN];
vector<int> v[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, K;
  cin >> n >> K;
  vector<int> id;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    id.push_back(--b);
    v[b].push_back(a);
  }
  
  sort(id.begin(), id.end());
  id.erase(unique(id.begin(), id.end()), id.end());
  
  for (int i: id) {
    sort(v[i].begin(), v[i].end(), greater<int>());
  }
  
  vector<P> p;
  for (int i: id) {
    for (int k = 1; k <= v[i].size(); ++k) {
      d[i][k] = d[i][k - 1] + v[i][k - 1] + (k - 1) * 2;
      p.push_back(make_pair(k, d[i][k]));
    }
  }
  
  for (int i = 0; i < id.size(); ++i) {
    for (int j = 0; j <= K; ++j) {
      dp[i + 1][j] = dp[i][j];
      for (int k = 0; k <= min(j, (int)v[id[i]].size()); ++k) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - k] + d[id[i]][k]);
      }
    }
  }
  
  cout << dp[id.size()][K] << '\n';
  return 0;
}