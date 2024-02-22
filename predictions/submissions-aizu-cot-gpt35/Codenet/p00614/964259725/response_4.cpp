#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_C = 6;
const int MAX_T = 10000;

int C[MAX_C] = {1, 5, 10, 50, 100, 500};
int P;
int N[MAX_C];
int dp[2][MAX_T];

int calc(int v) {
  return v / 500 + (v % 500) / 100 + ((v % 500) % 100) / 50 + (((v % 500) % 100) % 50) / 10 + ((((v % 500) % 100) % 50) % 10) / 5 + (((((v % 500) % 100) % 50) % 10) % 5) / 1;
}

int main() {
  while (cin >> P) {
    for (int i = 0; i < MAX_C; i++) {
      cin >> N[i];
    }
    if (P == 0)
      break;
    memset(dp, 1001001001, sizeof(dp));
    int extra = 0;
    for (int i = MAX_C - 1; i >= 0; i--) {
      while (P >= C[i] && P - C[i] >= 2500 && N[i]) {
        extra++;
        N[i]--;
        P -= C[i];
      }
      if (N[i])
        break;
    }
    dp[0][0] = 0;
    for (int i = 0; i < MAX_C; i++) {
      for (int j = 0; j < C[i]; j++) {
        deque<pair<int, int>> deq;
        for (int k = j; k < MAX_T; k += C[i]) {
          int w = MAX_T - k / C[i];
          dp[(i + 1) & 1][k] = min(dp[(i + 1) & 1][k], dp[i & 1][k]);
          while (!deq.empty() && deq.front().second + C[i] * N[i] < k)
            deq.pop_front();
          if (!deq.empty())
            dp[(i + 1) & 1][k] = min(dp[(i + 1) & 1][k], deq.front().first - w);
          if (!deq.empty() && deq.front().second + N[i] * C[i] <= k)
            deq.pop_front();
          deq.push_back(make_pair(dp[i & 1][k] + w, k));
        }
      }
    }
    int mi = 1001001001;
    for (int i = P; i < MAX_T; i++) {
      mi = min(mi, dp[0][i] + calc(i - P));
    }
    cout << mi + extra << endl;
  }
  return 0;
}