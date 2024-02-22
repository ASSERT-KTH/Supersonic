#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 51;
const int MAX_M = 101;

int N, M;
int A[3];
vector<set<int>> G(MAX_N);
bool used[MAX_N];
bool dp[2][MAX_N][MAX_N];

int main() {
  cin >> N >> M;
  for (int i = 0; i < 3; i++)
    cin >> A[i];
  for (int i = 0; i < M; i++) {
    int f, t;
    cin >> f >> t;
    f--;
    t--;
    G[f].insert(t);
  }
  
  for (int i = 0; i < N; i++)
    dp[0][i][i] = true;
  
  int cur = 1;
  for (int i = 1; i < MAX_M; i++) {
    for (int j = 0; j < N; j++) {
      for (int k : G[j]) {
        if (dp[1 - cur][j][k]) {
          for (int to : G[k]) {
            dp[cur][j][to] = true;
          }
        }
      }
    }
    cur = 1 - cur;
  }
  
  used[N - 1] = true;
  for (int ite = 1;; ite++) {
    vector<int> idx;
    for (int i = 0; i < N; i++) {
      if (used[i])
        continue;
      int cnt = 0;
      for (int j = 0; j < 3; j++) {
        int a = A[j];
        for (int k : G[i]) {
          if (dp[a][k][i] && used[k]) {
            cnt++;
            break;
          }
        }
      }
      if (cnt == 3) {
        idx.push_back(i);
      }
    }
    if (idx.empty()) {
      break;
    }
    for (int i : idx) {
      used[i] = true;
      if (used[0]) {
        cout << ite << endl;
        return 0;
      }
    }
  }
  
  cout << "IMPOSSIBLE" << endl;
  return 0;
}