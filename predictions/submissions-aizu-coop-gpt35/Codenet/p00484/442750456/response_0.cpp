#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define REP(i, k, n) for (int i = k; i < n; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1 << 30
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
  int n, K;
  cin >> n >> K;
  set<int> id;
  map<int, vector<int>> v;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    id.insert(b - 1);
    v[b - 1].push_back(a);
  }
  vector<P> p;
  for (int j : id) {
    sort(v[j].begin(), v[j].end(), greater<int>());
  }
  vector<ll> dp(K + 1);
  for (int j : id) {
    vector<ll> temp(K + 1);
    for (int k = 1; k <= v[j].size(); k++) {
      ll sum = v[j][k - 1] + (k - 1) * 2;
      dp[k] += sum;
      temp[k] += temp[k - 1] + sum;
      p.push_back(mp(k, temp[k]));
    }
    for (int i = K; i >= 0; i--) {
      if (i >= v[j].size()) {
        dp[i] = max(dp[i], dp[i - v[j].size()] + temp[v[j].size()]);
      }
    }
  }
  cout << dp[K] << endl;
  return 0;
}