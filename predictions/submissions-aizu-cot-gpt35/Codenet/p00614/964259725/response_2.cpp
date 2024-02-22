#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

const int MAX_COINS = 6;
const int MAX_AMOUNT = 10000;

int C[MAX_COINS] = {1, 5, 10, 50, 100, 500};
int P;
int N[MAX_COINS];
int dp[2][MAX_AMOUNT];

int calc(int v) {
  int ans = 0;
  for (int i = MAX_COINS - 1; i >= 0; i--) {
    ans += v / C[i];
    v %= C[i];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> P && P != 0) {
    for (int i = 0; i < MAX_COINS; i++) {
      cin >> N[i];
    }

    memset(dp, 0x3f, sizeof(dp)); // Initialize dp with a large value

    int cnt = 0;
    for (int i = MAX_COINS - 1; i >= 0; i--) {
      while (P - C[i] >= 2500 && N[i]) {
        cnt++;
        N[i]--;
        P -= C[i];
      }
      if (N[i] != 0) {
        break;
      }
    }

    dp[0][0] = 0;

    for (int i = 0; i < MAX_COINS; i++) {
      for (int j = 0; j < C[i]; j++) {
        deque<pair<int, int>> deq;
        for (int k = j; k < MAX_AMOUNT; k += C[i]) {
          int w = MAX_AMOUNT - k / C[i];
          dp[(i + 1) & 1][k] = min(dp[(i + 1) & 1][k], dp[i & 1][k]);
          while (!deq.empty() && deq.front().second + C[i] * N[i] < k) {
            deq.pop_front();
          }
          if (!deq.empty()) {
            dp[(i + 1) & 1][k] = min(dp[(i + 1) & 1][k], deq.front().first - w);
          }
          if (!deq.empty() && deq.front().second + N[i] * C[i] <= k) {
            deq.pop_front();
          }
          deq.push_back(make_pair(dp[i & 1][k] + w, k));
        }
      }
    }

    int mi = MAX_AMOUNT;
    for (int i = P; i < MAX_AMOUNT; i++) {
      mi = min(mi, dp[0][i] + calc(i - P));
    }
    cout << mi + cnt << endl;
  }

  return 0;
}