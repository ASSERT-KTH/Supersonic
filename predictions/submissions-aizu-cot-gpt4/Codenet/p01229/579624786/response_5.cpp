#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 150
using namespace std;

bool dp[2][MAX][MAX];
vector<pair<int, int>> states;
int input[MAX];

int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      states.clear();
      int N;
      cin >> N;
      for(int i = 0; i < N; i++) cin >> input[i];
      if(N <= 2) {
        cout << input[N - 1] << endl;
        continue;
      }
      int ans = input[N - 1];
      for(int cur = 1; cur < N - 1; cur++) {
        int idx = cur & 1;
        dp[idx][input[cur - 1]][input[cur]] = true;
        states.push_back(make_pair(input[cur - 1], input[cur]));
        int R = input[cur + 1];
        for(auto state : states) {
          int L = state.first, M = state.second;
          if(!dp[idx][L][M]) continue;
          if(M == 0) {
            if (cur + 2 < N) dp[1 - idx][M][R] = true;
            else ans = max(ans, R);
          } else {
            if (cur + 2 < N) {
              dp[1 - idx][M][R] = true;
              dp[1 - idx][M - 1][R + L] = true;
            } else {
              ans = max(ans, R + L);
            }
          }
        }
        states.clear();
        for(int i = 0; i < MAX; i++) {
          for(int j = 0; j < MAX; j++) {
            if(dp[idx][i][j]) {
              states.push_back(make_pair(i, j));
              dp[idx][i][j] = false;
            }
          }
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}