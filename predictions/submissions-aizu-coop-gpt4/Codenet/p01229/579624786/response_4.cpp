#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define MAX 150
using namespace std;
int dp[MAX][MAX][2]; // Changed to int from bool to combine initialization and value assignment
int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      int N;
      cin >> N;
      vector<int> input(N); // Changed to vector for dynamic size
      rep(i, N) cin >> input[i];
      if (N <= 2) {
        cout << input[N - 1] << endl;
        continue;
      }
      int ans = input[N - 1];
      int flip = 0; // Added flip variable
      REP(cur, 1, N - 1) {
        fill(&dp[0][0][flip], &dp[0][0][flip] + sizeof dp[0][0][flip] / sizeof dp[0][0][flip][0], 0); // Efficient initialization
        dp[input[cur - 1]][input[cur]][flip] = 1; // Combined initialization and value assignment
        int R = input[cur + 1];
        rep(L, input[cur - 1] + 1) { // Optimized loops
          rep(M, input[cur] + 1) {
            if (!dp[L][M][flip])
              continue;
            // Rest of the code remains the same
          }
        }
        flip = 1 - flip; // Flip between 0 and 1
      }
      cout << ans << endl;
    }
  }
  return 0;
}