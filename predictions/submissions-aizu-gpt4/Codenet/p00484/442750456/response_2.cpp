#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1 << 30
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
ll d[2005], dp[2005];
vector<int> v[2005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, K;
  cin >> n >> K;
  vector<int> id(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    id[i] = b - 1;
    v[b - 1].push_back(a);
  }
  sort(id.begin(), id.end());
  id.erase(unique(id.begin(), id.end()), id.end());
  for(auto &vec : v) {
    sort(vec.begin(), vec.end(), greater<int>());
  }
  vector<P> p;
  for(auto &j : id) {
    d[0] = 0;
    for(int k = 1; k <= v[j].size(); k++) {
      d[k] = d[k - 1] + v[j][k - 1] + (k - 1) * 2;
      p.push_back(mp(k, d[k]));
    }
  }
  rep(i, id.size()) {
    for(int j = K; j >= 0; j--) {
      for(int k = 0; k <= min(j, int(v[id[i]].size())); k++) {
        dp[j] = max(dp[j], dp[j - k] + d[k]);
      }
    }
  }
  cout << dp[K] << '\n';
  return 0;
}