#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, W;
  cin >> N >> W;
  vector<int> v(N), w(N), dp(W+1, 0);
  for (int i = 0; i < N; i++)
    cin >> v[i] >> w[i];
  for(int i=0; i<N; i++)
  for(int j=W; j>=w[i]; j--)
    dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
  cout << dp[W] << '\n';
  return 0;
}