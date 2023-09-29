#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vint;
typedef pair<int, int> pint;
typedef vector<pint> vpint;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define each(it, v)                                                            \
  for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define pb push_back
#define fi first
#define se second
template <typename A, typename B> inline void chmin(A &a, B b) {
  if (a > b)
    a = b;
}
template <typename A, typename B> inline void chmax(A &a, B b) {
  if (a < b)
    a = b;
}
int C[6] = {1, 5, 10, 50, 100, 500};
int P;
int N[6];
const int T = 10000;
int dp[2][T];
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
    rep(i, 6) cin >> N[i];
    if (P == 0)
      break;
    fill_n(*dp, 2 * T, 1001001001);
    int cnt