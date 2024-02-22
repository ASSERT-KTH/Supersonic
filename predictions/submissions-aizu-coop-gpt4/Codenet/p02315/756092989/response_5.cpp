#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vvi vector<vector<int>>
#define vec vector
#define pq priority_queue
#define all(v) (v).begin(), (v).end()
#define uniqueV(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
#define rep(i, n) for (int(i) = (0); (i) < (n); ++(i))
#define repp(i, m, n) for (int(i) = (m); (i) < (n); ++(i))

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const double PI = 3.14159265358979323846;

int n, W;
int weight[110], value[110];
int dp[10010]; // We have changed 2D array to 1D array

int main() {
  cin >> n >> W;
  rep(i, n) cin >> value[i] >> weight[i];

  memset(dp,0,sizeof(dp)); // Initialize all dp[w] to 0.

  for (int i = 0; i < n; i++) {
    for (int w = W; w >= 0; w--) { // We reverse the order of this loop because we are now using a 1D DP array
      if (w >= weight[i]) {
        dp[w] = max(dp[w - weight[i]] + value[i], dp[w]);
      }
      // No else part needed because if we can't take the item, nothing changes so we can leave dp[w] as it is
    }
  }
  cout << dp[W] << endl; // We changed dp[n][W] to dp[W] because we are now using a 1D DP array
  return 0;
}