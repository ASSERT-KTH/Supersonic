#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vvi vector<vector<int>>
#define vec vector
#define pq priority_queue
#define all(v) (v).begin(), (v).end()
#define uniqueV(x)                                                             \
  sort(x.begin(), x.end());                                                    \
  x.erase(unique(x.begin(), x.end()), x.end());
#define rep(i, n) for (int(i) = (0); (i) < (n); ++(i))
#define repp(i, m, n) for (int(i) = (m); (i) < (n); ++(i))
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y)                                                           \
  cerr << "(" << #x << ", " << #y << ") = "                                    \
       << "(" << x << ", " << y << ")" << endl;
#define debug3(x, y, z)                                                        \
  cerr << "(" << #x << ", " << #y << ", " << #z << ") = "                      \
       << "(" << x << ", " << y << ", " << z << ")" << endl;
#define debugB(value, size)                                                    \
  cerr << #value << ": " << bitset<size>(value) << endl;
#define line() cerr << "---------------" << endl;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const double PI = 3.14159265358979323846;
template <typename T> void printA(vector<T> &printArray, char between = ' ') {
  int paSize = printArray.size();
  for (int i = 0; i < paSize; i++) {
    cerr << printArray[i] << between;
  }
  if (between != '\n') {
    cerr << endl;
  }
}
int n, W;
int weight[110], value[110];
int dp[110][10010];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> W;
  rep(i, n) cin >> value[i] >> weight[i];
  rep(i, W + 1) dp[0][W] = 0;
  for (int i = 0; i < n; i++) {
    for (int w = 0; w <= W; w++) {
      if (w >= weight[i]) {
        dp[i + 1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
      } else {
        dp[i + 1][w] = dp[i][w];
      }
    }
  }
  cout << dp[n][W] << endl;
  return 0;
}
