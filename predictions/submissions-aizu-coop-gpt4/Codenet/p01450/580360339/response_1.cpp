#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int N, W;
int w[201];
ll dp[10001];
int main() {
  cin >> N >> W;
  for (int i = 0; i < N; i++)
    cin >> w[i];
  sort(w, w + N);
  dp[0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = W; j >= w[i]; j--) {
      dp[j] += dp[j - w[i]];
      dp[j] %= mod;
    }
  }
  ll sum = 0;
  for (int j = 0; j <= W; j++) {
    sum += dp[j];
    sum %= mod;
  }
  cout << sum << endl;
  return 0;
}