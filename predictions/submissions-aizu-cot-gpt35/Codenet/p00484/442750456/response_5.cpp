#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main() {
  int n, K;
  cin >> n >> K;
  vector<int> id, v;
  vector<vector<ll>> d;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    id.push_back(b - 1);
    v.push_back(a);
  }

  sort(id.begin(), id.end());
  id.erase(unique(id.begin(), id.end()), id.end());

  d.resize(id.size(), vector<ll>(K + 1, 0));
  vector<P> p;

  for (int i = 0; i < id.size(); i++) {
    int j = id[i];
    sort(v.begin(), v.end(), greater<int>());

    for (int k = 1; k <= v.size(); k++) {
      d[j][k] += d[j][k - 1] + v[k - 1] + (k - 1) * 2;
      p.push_back(make_pair(k, d[j][k]));
    }
  }

  vector<ll> dp(K + 1, 0);

  for (int i = 0; i < id.size(); i++) {
    for (int j = K; j >= 0; j--) {
      ll res = dp[j];

      for (int k = 0; k <= v.size(); k++) {
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