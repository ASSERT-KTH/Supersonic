#include <iostream>
#include <vector>
#define MAX 150

using namespace std;

bool dp[MAX][MAX];

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
      for (int cur = 1; cur < N - 1; cur++) {
        dp[input[cur - 1]][input[cur]] = true;
        int R = input[cur + 1];
        for (int k = 0; k < MAX * MAX; k++) {
          int L = k / MAX;
          int M = k % MAX;
          if (M == 0) {
            if (cur + 2 < N) {
              dp[M][R] = true;
            } else {
              ans = max(ans, R);
            }
          } else {
            if (cur + 2 < N) {
              dp[M][R] = true;
              dp[M - 1][R + L] = true;
            } else {
              ans = max(ans, R + L);
            }
          }
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}