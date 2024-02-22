#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

const int MAX_AMOUNT = 10000;
const int INF = 1001001001;
const int COINS[6] = {1, 5, 10, 50, 100, 500};
int num_coins[6];
int dp[6][MAX_AMOUNT];

template <typename A, typename B> 
inline void minimize(A &a, B b) {
  if (a > b)
    a = b;
}

int calc(int v) {
  int ans = 0;
  for (int i = 5; i >= 0; i--) {
    ans += v / COINS[i];
    v %= COINS[i];
  }
  return ans;
}

int main() {
  int P;
  while (cin >> P) {
    for (int i = 0; i < 6; i++)
      cin >> num_coins[i];
      
    if (P == 0)
      break;
      
    fill_n(*dp, 6 * MAX_AMOUNT, INF);
    int cnt = 0;
    
    for (int i = 5; i >= 0; i--) {
      while (P - COINS[i] >= 2500 && num_coins[i]) {
        cnt++;
        num_coins[i]--;
        P -= COINS[i];
      }
      if (num_coins[i])
        break;
    }
    
    dp[0][0] = 0;
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < COINS[i]; j++) {
        deque<pair<int, int>> deq;
        for (int k = j; k < MAX_AMOUNT; k += COINS[i]) {
          int w = MAX_AMOUNT - k / COINS[i];
          minimize(dp[(i + 1) % 6][k], dp[i % 6][k]);
          while (!deq.empty() && deq.front().second + COINS[i] * num_coins[i] < k)
            deq.pop_front();
          if (!deq.empty())
            minimize(dp[(i + 1) % 6][k], deq.front().first - w);
          if (!deq.empty() && deq.front().second + num_coins[i] * COINS[i] <= k)
            deq.pop_front();
          deq.push_back(make_pair(dp[i % 6][k] + w, k));
        }
      }
    }
    
    int mi = INF;
    for (int i = P; i < MAX_AMOUNT; i++) {
      minimize(mi, dp[0][i] + calc(i - P));
    }
    
    cout << mi + cnt << endl;
  }
  
  return 0;
}