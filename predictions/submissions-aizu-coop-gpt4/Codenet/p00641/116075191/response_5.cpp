#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> b[100100];
int f[2][100100];
bool v[100100];
int dp[100100];

int dfs(int s, int now, int maxi, int num) {
  if (dp[now] != -1) return dp[now]; // return memoized value if available

  v[now] = true;
  for (auto& i : b[now]) {
    if (!v[i.first]) {
      if (maxi == i.second)
        num = (num + 1) % 10007; // moved modulo operation here
      else if (maxi < i.second) {
        maxi = i.second;
        num = 1;
      }
      if (i.first == s)
        return dp[now] = num; // memoize return value
      return dp[now] = dfs(s, i.first, maxi, num); // memoize return value
    }
  }
  if (maxi == f[1][s])
    return dp[now] = (num + 1) % 10007; // moved modulo operation here
  else if (maxi < f[1][s])
    return dp[now] = 1; // memoize return value
  else
    return dp[now] = num; // memoize return value
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O
  cin.tie(NULL);

  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      int b1, f1, b2, f2;
      cin >> b1 >> f1 >> b2 >> f2;
      b[i].push_back({b1, f1});
      b[i].push_back({b2, f2});
      v[i] = false;
      dp[i] = -1; // initialize DP array
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        v[i] = true;
        ans = (ans * dfs(i, b[i][0].first, b[i][0].second, 1)) % 10007; // moved modulo operation here
      }
    }
    cout << ans << endl;
  }
}