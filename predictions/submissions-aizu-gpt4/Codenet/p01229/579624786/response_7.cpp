#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 150
#define rep(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int dp[MAX][MAX][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    rep(i, MAX) rep(j, MAX) rep(l, 2) dp[i][j][l] = false;

    int N;
    cin >> N;

    vector<int> input(N);

    for (auto& in : input) cin >> in;

    if (N <= 2) {
        cout << input[N - 1] << '\n';
        continue;
    }

    int ans = input[N - 1];

    for (int cur = 1; cur < N - 1; ++cur) {
        dp[input[cur - 1]][input[cur]][cur & 1] = true;
        int R = input[cur + 1];

        rep(L, MAX) {
          rep(M, MAX) {
            if (!dp[L][M][cur & 1])
              continue;

            if (cur + 2 < N) {
              dp[M][R][(cur + 1) & 1] = true;

              if (M > 0) 
                dp[M - 1][R + L][(cur + 1) & 1] = true;
            } else {
              ans = max(ans, M > 0 ? R + L : R);
            }
          }
        }

        rep(i, MAX) rep(j, MAX) dp[i][j][cur & 1] = false;
      }

      cout << ans << '\n';
    }

  return 0;
}
