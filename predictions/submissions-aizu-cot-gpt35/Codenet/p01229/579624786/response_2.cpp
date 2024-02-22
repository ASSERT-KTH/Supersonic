#include <iostream>
#define MAX 150
using namespace std;

bool dp[MAX][MAX][2];

int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      int N;
      cin >> N;
      int input;
      cin >> input;
      if (N <= 2) {
        cout << input << endl;
        continue;
      }
      int ans = input;
      for (int cur = 1; cur < N - 1; cur++) {
        dp[input][input][cur & 1] = true;
        int R;
        cin >> R;
        for (int L = 0; L <= input; L++) {
          for (int M = 0; M <= input; M++) {
            if (!dp[L][M][cur & 1])
              continue;
            if (M == 0) {
              if (cur + 2 < N) {
                dp[M][R][(cur + 1) & 1] = true;
              } else
                ans = max(ans, R);
            } else {
              if (cur + 2 < N) {
                dp[M][R][(cur + 1) & 1] = true;
                dp[M - 1][R + L][(cur + 1) & 1] = true;
              } else {
                ans = max(ans, R + L);
              }
            }
          }
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}