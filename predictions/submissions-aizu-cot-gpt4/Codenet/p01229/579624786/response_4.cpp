#include <iostream>
#include <vector>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define MAX 150
using namespace std;
bool dp1[MAX][MAX];
bool dp2[MAX][MAX];
int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      rep(i, MAX) rep(j, MAX) {
        dp1[i][j] = false;
        dp2[i][j] = false;
      }
      int N;
      cin >> N;
      int input[N];
      rep(i, N) cin >> input[i];
      if (N <= 2) {
        cout << input[N - 1] << endl;
        continue;
      }
      int ans = input[N - 1];
      REP(cur, 1, N - 1) {
        bool (*dp_curr)[MAX], (*dp_next)[MAX];
        if (cur & 1) {
          dp_curr = dp1;
          dp_next = dp2;
        } else {
          dp_curr = dp2;
          dp_next = dp1;
        }
        dp_curr[input[cur - 1]][input[cur]] = true;
        int R = input[cur + 1];
        rep(L, MAX) {
          rep(M, MAX) {
            if (!dp_curr[L][M])
              continue;
            if (M == 0) {
              if (cur + 2 < N) {
                dp_next[M][R] = true;
              } else
                ans = max(ans, R);
            } else {
              if (cur + 2 < N) {
                dp_next[M][R] = true;
                dp_next[M - 1][R + L] = true;
              } else {
                ans = max(ans, R + L);
              }
            }
          }
        }
        rep(i, MAX) rep(j, MAX) dp_curr[i][j] = false;
      }
      cout << ans << endl;
    }
  }
  return 0;
}