#include <iostream>
using namespace std;

int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      int N;
      cin >> N;
      int* input = new int[N];
      for (int i = 0; i < N; i++) {
        cin >> input[i];
      }
      if (N <= 2) {
        cout << input[N - 1] << '\n';
        delete[] input;
        continue;
      }
      int ans = input[N - 1];
      bool*** dp = new bool**[N];
      for (int i = 0; i < N; i++) {
        dp[i] = new bool*[101];
        for (int j = 0; j < 101; j++) {
          dp[i][j] = new bool[2];
          for (int l = 0; l < 2; l++) {
            dp[i][j][l] = false;
          }
        }
      }
      for (int cur = 1; cur < N - 1; cur++) {
        dp[input[cur - 1]][input[cur]][cur & 1] = true;
        int prevCur = (cur + 1) & 1;
        for (int L = 0; L < 101; L++) {
          for (int M = 0; M < 101; M++) {
            if (!dp[L][M][prevCur]) {
              continue;
            }
            int R = input[cur + 1];
            if (M == 0) {
              if (cur + 2 < N) {
                dp[M][R][cur & 1] = true;
              } else {
                ans = max(ans, R);
              }
            } else {
              if (cur + 2 < N) {
                dp[M][R][cur & 1] = true;
                dp[M - 1][R + L][cur & 1] = true;
              } else {
                ans = max(ans, R + L);
              }
            }
          }
        }
        for (int i = 0; i < 101; i++) {
          for (int j = 0; j < 101; j++) {
            dp[i][j][prevCur] = false;
          }
        }
      }
      cout << ans << '\n';
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < 101; j++) {
          delete[] dp[i][j];
        }
        delete[] dp[i];
      }
      delete[] dp;
      delete[] input;
    }
  }
  return 0;
}