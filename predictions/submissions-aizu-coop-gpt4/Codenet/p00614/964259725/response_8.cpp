#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vint;
typedef pair<int, int> pint;
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fi first
#define se second
template <typename A, typename B> inline void chmin(A &a, B b) {
  if (a > b)
    a = b;
}
int C[6] = {1, 5, 10, 50, 100, 500};
int P;
int N[6];
const int T = 10000;
int dp[T];
int calc(int v) {
  int ans = 0;
  for (int i = 5; i >= 0; i--) {
    ans += v / C[i];
    v %= C[i];
  }
  return ans;
}
signed main() {
  while (cin >> P) {
    for(int i = 0; i < 6; i++) cin >> N[i];
    if (P == 0)
      break;
    fill_n(dp, T, 1001001001);
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
    dp[0] = 0;
    for(int i = 0; i < 6; i++) {
      deque<pint> deq;
      for(int k = 0; k < T; k++) {
        int w = T - k / C[i];
        while(deq.size() && deq.front().se + C[i]*N[i] <= k) deq.pop_front();
        if(k >= C[i]){
            deq.pb(pint(dp[k - C[i]] + w, k));
        }
        if(deq.size()){
            chmin(dp[k], deq.front().fi - w);
        }
      }
    }
    int mi = 1001001001;
    for (int i = P; i < T; i++) {
      chmin(mi, dp[i] + calc(i - P));
    }
    cout << mi + cnt << endl;
  }
  return 0;
}