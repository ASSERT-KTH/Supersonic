#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define MAX 150
using namespace std;

bool dp[2][MAX][MAX];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    int input[N];
    for(int i = 0; i < N; i++) cin >> input[i];
    
    if (N <= 2) {
      cout << input[N - 1] << endl;
      continue;
    }
    
    int ans = input[N - 1];
    fill(dp[0][0], dp[2][0], false);
    
    for(int cur = 1; cur < N - 1; cur++) {
        dp[cur & 1][input[cur - 1]][input[cur]] = true;
        int R = input[cur + 1];
        
        bool hasNext = (cur + 2 < N);
        
        for(int M = 0; M < MAX; M++) {
            for(int L = 0; L < MAX; L++) {
                if (!dp[cur & 1][L][M])
                    continue;
                if (M == 0) {
                    if (hasNext) {
                        dp[(cur + 1) & 1][M][R] = true;
                    } else
                        ans = max(ans, R);
                } else {
                    if (hasNext) {
                        dp[(cur + 1) & 1][M][R] = true;
                        dp[(cur + 1) & 1][M - 1][R + L] = true;
                    } else {
                        ans = max(ans, R + L);
                    }
                }
            }
        }
        for(int i = 0; i < MAX; i++) for(int j = 0; j < MAX; j++) dp[cur & 1][i][j] = false;
    }
    cout << ans << endl;
  }
  return 0;
}