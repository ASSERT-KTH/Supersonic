#include <bits/stdc++.h>
using namespace std;
#define for_(i, a, b) for (int i = (a); i < (b); ++i)
#define for_rev(i, a, b) for (int i = (a); i >= (b); --i)
typedef vector<int> Ary;
typedef vector<Ary> Mat;
struct Edge {
  int to, c;
};
void maxUpdate(int &a, int b) { a = max(a, b); }
void mul(Mat &res, Mat &a, Mat &b) {
  int N = a.size();
  res = a;
  for_(i, 0, N) for_(j, 0, N) for_(k, 0, N) {
    if (a[i][k] >= 0 && b[k][j] >= 0)
      maxUpdate(res[i][j], a[i][k] + b[k][j]);
  }
}
int V, K, E, dp[155][155], prv[155][155];
vector<vector<Edge>> adj;
void restore(int step, int v) {
  int c = step;
  vector<int> path;
  while (v != -1) {
    path.push_back(v);
    v = prv[c--][v];
  }
  reverse(path.begin(), path.end());
  for_(i, 0, step + 1) cout << path[i] << (i < step ? " " : "\n");
}
bool shortphase() {
  memset(dp, -1, sizeof(dp));
  memset(prv, -1, sizeof(prv));
  for_(v, 0, V) dp[0][v] = 0;
  int max_score = -1, step = -1, terminal = -1;
  for_(i, 0, 80) {
    for_(v, 0, V) {
      if (dp[i][v] == -1)
       