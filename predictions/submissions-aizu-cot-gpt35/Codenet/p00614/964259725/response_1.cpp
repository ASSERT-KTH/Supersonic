#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int C[6] = {1, 5, 10, 50, 100, 500};
int P;
int N[6];

int calc(int v) {
  int ans = 0;
  for (int i = 5; i >= 0; i--) {
    ans += v / C[i];
    v %= C[i];
  }
  return ans;
}

int main() {
  while (cin >> P) {
    for (int i = 0; i < 6; i++)
      cin >> N[i];
    if (P == 0)
      break;
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
    int dp[2][P + 1];
    fill_n(*dp, 2 * (P + 1), 1001001001);
    dp[0][0] = 0;
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < C[i]; j++) {
        deque<pair<int, int>> deq;
        for (int k = j; k <= P; k += C[i]) {
          int w = P - k / C[i];
          if (dp[i & 1][k] + w < dp[(i + 1) & 1][k])
            dp[(i + 1) & 1][k] = dp[i & 1][k] + w;
          while (!deq.empty() && deq.front().second + C[i] * N[i] < k)
            deq.pop_front();
          if (!deq.empty() && deq.front().first - w < dp[(i + 1) & 1][k])
            dp[(i + 1) & 1][k] = deq.front().first - w;
          if (!deq.empty() && deq.front().second + N[i] * C[i] <= k)
            deq.pop_front();
          deq.push_back(make_pair(dp[i & 1][k] + w, k));
        }
      }
    }
    int mi = 1001001001;
    for (int i = P; i <= P + 500; i++) {
      int num = calc(i - P);
      if (dp[0][i] + num < mi)
        mi = dp[0][i] + num;
    }
    cout << mi + cnt << endl;
  }
  return 0;
}