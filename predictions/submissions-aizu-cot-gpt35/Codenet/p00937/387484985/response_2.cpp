#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MAX_N = 51;
const int MAX_A = 101;
const int MAX_ITERATIONS = MAX_N;

int N, M;
int A[3];
vector<int> G[MAX_N];
vector<bool> used(MAX_N, false);
vector<vector<bitset<MAX_N>>> dp(MAX_A, vector<bitset<MAX_N>>(MAX_N));

int main() {
  cin >> N >> M;
  for (int i = 0; i < 3; i++)
    cin >> A[i];
  for (int i = 0; i < M; i++) {
    int f, t;
    cin >> f >> t;
    f--;
    t--;
    G[f].push_back(t);
  }
  for (int i = 0; i < N; i++)
    dp[0][i][i] = true;
  for (int i = 1; i < MAX_A; i++) {
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
  for (int ite = 1; ite <= MAX_ITERATIONS; ite++) {
    bool ok = false;
    bitset<MAX_N> idx;
    for (int i = 0; i < N; i++) {
      if (used[i])
        continue;
      int cnt = 0;
      for (int j = 0; j < 3; j++) {
        int a = A[j];
        for (int k = 0; k < N; k++) {
          if (dp[a][i][k] && used[k]) {
            cnt++;
            break;
          }
        }
      }
      if (cnt == 3) {
        ok = true;
        idx[i] = true;
      }
    }
    if (ok) {
      used |= idx;
      if (used[0]) {
        cout << ite << endl;
        return 0;
      }
    } else {
      break;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}