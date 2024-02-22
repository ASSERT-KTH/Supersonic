#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int C[6] = {1, 5, 10, 50, 100, 500};
int P;
int N[6];
const int T = 10000;
int dp[2][T];
int numCoins[T];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> P) {
    if (P == 0)
      break;
      
    for (int i = 0; i < 6; i++)
      cin >> N[i];
      
    int cnt = 0;
    for (int i = 5; i >= 0; i--) {
      while (P - C[i] >= 2500 && N[i]) {
        cnt++;
        N[i]--;
        P -= C[i];
      }
      if (N[i])
        break;
    }
    
    for (int i = 0; i < T; i++)
      dp[0][i] = 1001001001;
    
    dp[0][0] = 0;
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < C[i]; j++) {
        int best = 1001001001;
        for (int k = j; k < T; k += C[i]) {
          int w = T - k / C[i];
          best = min(best, dp[i & 1][k]);
          
          if (k >= C[i] * N[i])
            best = min(best, dp[i & 1][k - C[i] * N[i]] + w);

          dp[(i + 1) & 1][k] = best;
        }
      }
    }
    
    int mi = 1001001001;
    for (int i = P; i < T; i++) {
      mi = min(mi, dp[0][i] + numCoins[i - P]);
    }
    cout << mi + cnt << endl;
  }

  return 0;
}