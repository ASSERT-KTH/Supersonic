#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int a, b, c;
vector<int> G[51];
bool used[51];
bool dp[101][51][51];
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> N >> M;
  cin >> a >> b >> c;
  int maxA = max({a, b, c});
  for (int i = 0; i < M; i++) {
    int f, t;
    cin >> f >> t;
    f--;
    t--;
    G[f].push_back(t);
  }
  for (int i = 0; i < N; i++)
    dp[0][i][i] = true;
  for (int i = 1; i <= maxA; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (dp[i - 1][j][k]) {
          for (int to : G[k]) {
            dp[i][j][to] = true;
          }
        }
      }
    }
  }
  used[N - 1] = true;
  for (int ite = 1;; ite++) {
    bool ok = false;
    vector<int> idx;
    for (int i = 0; i < N; i++) {
      if (used[i])
        continue;
      int cnt = 0;
      if ((dp[a][i][k] && used[k]) || (dp[b][i][k] && used[k]) || (dp[c][i][k] && used[k]))
        cnt++;
      if (cnt == 3) {
        ok = true;
        idx.push_back(i);
      }
    }
    if (ok) {
      for (int i : idx) {
        used[i] = true;
      }
    } else {
      break;
    }
    if (used[0]) {
      cout << ite << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}