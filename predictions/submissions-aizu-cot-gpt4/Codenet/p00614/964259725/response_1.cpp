#include <iostream>
#include <vector>
#include <deque>
using namespace std;
using vint = vector<long long>;
using pint = pair<long long, long long>;
using vpint = vector<pint>;
long long C[6] = {1, 5, 10, 50, 100, 500};
long long P;
long long N[6];
const long long T = 10000;
long long dp[2][T];
long long calc(long long v) {
  long long ans = 0;
  for (long long i = 5; i >= 0; i--) {
    ans += v / C[i];
    v %= C[i];
  }
  return ans;
}
int main() {
  while (cin >> P) {
    for(long long i = 0; i < 6; i++) cin >> N[i];
    if (P == 0)
      break;
    for(long long i = 0; i < 2 * T; i++) dp[i/T][i%T] = 1001001001;
    long long cnt = 0;
    for (long long i = 5; i >= 0; i--) {
      if (P - C[i] >= 2500 && N[i]) {
        long long times = P/C[i];
        cnt += times;
        N[i] -= times;
        P -= times * C[i];
      }
      if (N[i])
        break;
    }
    dp[0][0] = 0;
    for(long long i = 0; i < 6; i++) {
      for(long long j = 0; j < C[i]; j++) {
        deque<pint> deq;
        for (long long k = j; k < T; k += C[i]) {
          long long w = T - k / C[i];
          dp[(i + 1) & 1][k] = min(dp[(i + 1) & 1][k], dp[i & 1][k]);
          while (deq.size() && deq.front().second + C[i] * N[i] < k)
            deq.pop_front();
          if (deq.size())
            dp[(i + 1) & 1][k] = min(dp[(i + 1) & 1][k], deq.front().first - w);
          if (deq.size() && deq.front().second + N[i] * C[i] <= k)
            deq.pop_front();
          deq.push_back(pint(dp[i & 1][k] + w, k));
        }
      }
    }
    long long mi = 1001001001;
    for (long long i = P; i < T; i++) {
      mi = min(mi, dp[0][i] + calc(i - P));
    }
    cout << mi + cnt << endl;
  }
  return 0;
}