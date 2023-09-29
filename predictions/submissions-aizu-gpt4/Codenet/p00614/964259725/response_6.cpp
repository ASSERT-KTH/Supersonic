#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pint;

const int C[6] = {1, 5, 10, 50, 100, 500};
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
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  while (cin >> P) {
    for(int i=0; i<6; ++i) cin >> N[i];
    if (P == 0)
      break;
    fill_n(*dp, 2*T, 1001001001);
    int cnt = 0;
    for (int i = 5; i >= 0; i--) {
      while (P - C[i] >= 2500 && N[i]) {
        cnt++;
        N[i]--;
        P -= C[i];
      }
      if (N[i]) break;
    }
    dp[0][0] = 0;
    for(int i=0; i<6; ++i) {
      for(int j=0; j<C[i]; ++j) {
        deque<pint> deq;
        for (int k = j; k < T; k += C[i]) {
          int w = T - k / C[i];
          dp[(i + 1) & 1][k] = min(dp[i & 1][k], deq.size() ? deq.front().first - w : 1001001001);
          while (deq.size() && deq.front().second + C[i] * N[i] < k) deq.pop_front();
          while (deq.size() && deq.back().first >= dp[i & 1][k] + w) deq.pop_back();
          deq.push_back(make_pair(dp[i & 1][k] + w, k));
        }
      }
    }
    int mi = *min_element(dp[0]+P, dp[0]+T, [](int a, int b){return a + calc(T - a) < b + calc(T - b);});
    cout << mi + cnt << "\n";
  }
  return 0;
}