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
int dp[55][3030];
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  int const MOD = 100000;
  while (true) {
    int N, M, S; cin >> N >> M >> S;
    if (!(N | M | S)) break;
    zero(dp);
    dp[0][0] = 1;
    REP(add, 1, M + 1) {
      for (int currIndex = N * N; currIndex >= 1; currIndex--) {
        for (int currSum = add; currSum <= S; currSum++) {
          dp[currIndex][currSum] = (dp[currIndex][currSum] + dp[currIndex - 1][currSum - add]) % MOD;
        }
      }
    }
    cout << dp[N * N][S] << endl;
  }
  return 0;
}