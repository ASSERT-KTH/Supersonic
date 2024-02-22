#include <iostream>
#include <vector>
using namespace std;
vector<int> dp(10001, 0);
int main() {
  std::ios_base::sync_with_stdio(false);
  int N, W;
  cin >> N >> W;
  vector<int> v(N), w(N);
  for (int i = 0; i < N; i++)
    cin >> v[i] >> w[i];
  for (int i = 0; i < N; i++) {
    for (int j = W; j >= w[i]; j--) {
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
  }
  cout << dp[W] << endl;
  return 0;
}