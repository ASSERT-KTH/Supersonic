#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pint;

int calc(int v) {
  int ans = 0;
  int C[6] = {1, 5, 10, 50, 100, 500};
  for (int i = 5; i >= 0; i--) {
    ans += v / C[i];
    v %= C[i];
  }
  return ans;
}

int main() {
  int P;
  while (cin >> P) {
    if (P == 0)
      break;
    int N[6];
    for (int i = 0; i < 6; i++) {
      cin >> N[i];
    }
    const int T = 10000;
    vector<int> dp[2];
    dp[0].resize(T, 1001001001);
    dp[1].resize(T, 1001001001);
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
    dp[0][0] = 0;
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < C[i]; j++) {
        vector<pint> deq;
        for (int k = j; k < T; k += C[i]) {
          int w = T - k / C[i];
          dp[(i + 1) & 1][k] = min(dp[(i + 1) & 1][k], dp[i & 1][k]);
          while (!deq.empty() && deq.front().second + C[i] * N[i] < k)
            deq.erase(deq.begin());
          if (!deq.empty())
            dp[(i + 1) & 1][k] = min(dp[(i + 1) & 1][k], deq.front().first - w);
          if (!deq.empty() && deq.front().second + N[i] * C[i] <= k)
            deq.erase(deq.begin());
          deq.push_back(make_pair(dp[i & 1][k] + w, k));
        }
      }
    }
    int mi = 1001001001;
    for (int i = P; i < T; i++) {
      mi = min(mi, dp[0][i] + calc(i - P));
    }
    cout << mi + cnt << endl;
  }
  return 0;
}