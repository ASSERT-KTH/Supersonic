#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define INF 1 << 30
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
ll d[15][2005], dp[2005][2005];
int main() {
  int n, K;
  cin >> n >> K;
  set<int> id;
  vector<int> v[2005];
  v->reserve(2005);  // reserve memory in advance
  for(int i=0; i<n; i++) {
    int a, b;
    cin >> a >> b;
    id.insert(b - 1);
    v[b - 1].push_back(a);
  }
  for(auto const& i: id) {
    sort(v[i].begin(), v[i].end(), greater<int>());
  }
  fill(&d[0][0], &d[0][0] + sizeof(d), 0);
  vector<P> p;
  for(auto const& i: id) {
    for(int k=1; k< v[i].size() + 1; k++) {
      d[i][k] += d[i][k - 1] + v[i][k - 1] + (k - 1) * 2;
      p.push_back(make_pair(k, d[i][k]));
    }
  }
  fill(&dp[0][0], &dp[0][0] + sizeof(dp), 0);
  int id_size = id.size();
  for(int i=0; i<id_size; i++) {
    for(int j=0; j<K+1; j++) {
      ll res = dp[i][j];
      for(int k=0; k< v[i].size() + 1; k++) {
        if (j >= k) {
          res = max(res, dp[i][j - k] + d[i][k]);
        }
      }
      dp[i + 1][j] = res;
    }
  }
  cout << dp[id_size][K] << endl;
  return 0;
}