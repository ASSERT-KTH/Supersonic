#include <iostream>
#include <vector>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define MAX 150
using namespace std;

bool dp[MAX][MAX][2];

int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      int N;
      cin >> N;
      vector<int> input(N);
      rep(i, N) cin >> input[i];
      if (N <= 2) {
        cout << input[N - 1] << endl;
        continue;
      }
      int ans = input[N - 1];
      int curIndex = 1;
      dp[input[curIndex - 1]][input[curIndex]][curIndex & 1] = true;
      REP(cur, 1, N - 1) {
        int R = input[cur + 1];
        rep(L, MAX) {
          rep(M, MAX) {
            if (!dp[L][M][curIndex & 1])
              continue;
            if (M == 0) {
              if (cur + 2 < N) {
                dp[M][R][(curIndex + 1) & 1] = true;
              } else
                ans = max(ans, R);
            } else {
              if (cur + 2 < N) {
                dp[M][R][(curIndex + 1) & 1] = true;
                dp[M - 1][R + L][(curIndex + 1) & 1] = true;
              } else {
                ans = max(ans, R + L);
              }
            }
          }
        }
        curIndex++;
      }
      cout << ans << endl;
    }
  }
  return 0;
}