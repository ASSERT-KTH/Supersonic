#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 150;

int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      int N;
      cin >> N;
      vector<int> input(N);
      for (int i = 0; i < N; i++) {
        cin >> input[i];
      }
      if (N <= 2) {
        cout << input[N - 1] << endl;
        continue;
      }
      int ans = input[N - 1];
      bool dp[MAX][MAX][2] = {false};
      int curAnd1;
      bool curPlus2LessThanN;
      for (int cur = 1; cur < N - 1; cur++) {
        curAnd1 = cur & 1;
        curPlus2LessThanN = cur + 2 < N;
        dp[input[cur - 1]][input[cur]][curAnd1] = true;
        int R = input[cur + 1];
        for (int L = 0; L < MAX; L++) {
          for (int M = 0; M < MAX; M++) {
            if (!dp[L][M][curAnd1])
              continue;
            if (M == 0) {
              if (curPlus2LessThanN) {
                dp[M][R][curAnd1 ^ 1] = true;
              } else {
                ans = max(ans, R);
              }
            } else {
              if (curPlus2LessThanN) {
                dp[M][R][curAnd1 ^ 1] = true;
                dp[M - 1][R + L][curAnd1 ^ 1] = true;
              } else {
                ans = max(ans, R + L);
              }
            }
          }
        }
        for (int i = 0; i < MAX; i++) {
          for (int j = 0; j < MAX; j++) {
            dp[i][j][curAnd1] = false;
          }
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}