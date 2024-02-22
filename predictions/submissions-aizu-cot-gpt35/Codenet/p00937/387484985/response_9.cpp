#include <iostream>
#include <vector>
using namespace std;

int N, M;
int A[3];
vector<int> G[51];
bool dp[51][51];
int used;

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
    dp[0][i] = true;
  for (int i = 1; i < 101; i++) {
    for (int j = 0; j < N; j++) {
      if (dp[i - 1][j]) {
        for (int to : G[j]) {
          dp[i][to] = true;
        }
      }
    }
  }
  used = (1 << (N - 1)); // Set the MSB of used to true
  for (int ite = 1;; ite++) {
    bool ok = false;
    vector<int> idx;
    for (int i = 0; i < N; i++) {
      if (used & (1 << i))
        continue;
      int cnt = 0;
      for (int j = 0; j < 3; j++) {
        int a = A[j];
        if (dp[a][i] && (used & (1 << j))) {
          cnt++;
          break;
        }
      }
      if (cnt == 3) {
        ok = true;
        idx.push_back(i);
      }
    }
    if (ok) {
      for (int i : idx) {
        used |= (1 << i);
      }
      if (used & 1) {
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