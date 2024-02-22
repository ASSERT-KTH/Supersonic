#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll d[2005][2005], dp[2005][2005];

int main() {
  int n, K;
  cin >> n >> K;
  vector<set<int>> v(K);
  
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v[b - 1].insert(a);
  }
  
  vector<int> id;
  for (int i = 0; i < K; i++) {
    if (!v[i].empty()) {
      id.push_back(i);
    }
  }
  
  memset(d, 0, sizeof(d));
  vector<P> p;
  
  for (int i = 0; i < id.size(); i++) {
    int j = id[i];
    int k = 1;
    for (const auto& val : v[j]) {
      d[j][k] += d[j][k - 1] + val + (k - 1) * 2;
      p.push_back(make_pair(k, d[j][k]));
      k++;
    }
  }
  
  memset(dp, 0, sizeof(dp));
  
  for (int i = 0; i < id.size(); i++) {
    for (int j = 0; j <= K; j++) {
      ll res = dp[i][j];
      for (int k = 0; k <= v[id[i]].size(); k++) {
        if (j >= k) {
          res = max(res, dp[i][j - k] + d[id[i]][k]);
        }
      }
      dp[i + 1][j] = res;
    }
  }
  
  cout << dp[id.size()][K] << endl;
  
  return 0;
}