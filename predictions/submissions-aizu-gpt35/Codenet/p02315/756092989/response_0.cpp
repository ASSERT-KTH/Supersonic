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

const int MAX_N = 105;
const int MAX_W = 100005;

int n, W;
int weight[MAX_N], value[MAX_N];
int dp[MAX_W];

int main() {
  cin >> n >> W;
  rep(i, n) cin >> value[i] >> weight[i];
  rep(i, n) {
    for (int w = W; w >= weight[i]; w--) {
      dp[w] = max(dp[w - weight[i]] + value[i], dp[w]);
    }
  }
  cout << dp[W] << endl;
  return 0;
}