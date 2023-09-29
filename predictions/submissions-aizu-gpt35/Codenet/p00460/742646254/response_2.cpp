#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a)                                                               \
  { cout << #a << " = " << a << endl; }
template <class T1, class T2> inline bool minimize(T1 &a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2> inline bool maximize(T1 &a, T2 b) {
  return a < b && (a = b, 1);
}
typedef long long ll;
int const inf = 1 << 29;
int dp[3030];
int main() {
  int const MOD = 100000;
  for (int N, M, S; cin >> N >> M >> S && (N | M | S);) {
    zero(dp);
    dp[0] = 1;
    REP(add, 1, M + 1) {
      for (int currSum = S; currSum >= add; currSum--) {
        rep(i, N * N) {
          if (currSum - add*i < add) break;
          dp[currSum] = (dp[currSum] + dp[currSum - add*i]) % MOD;
        }
      }
    }
    cout << dp[S] << endl;
  }
  return 0;
}