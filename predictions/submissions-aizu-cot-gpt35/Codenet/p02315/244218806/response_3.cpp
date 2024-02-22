#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> v(N), w(N);
  for (int& x : v)
    cin >> x;
  for (int& x : w)
    cin >> x;

  vector<int> dp(W + 1, 0);
  for (int i = N - 1; i >= 0; i--) {
    for (int j = W; j >= 0; j--) {
      if (j - w[i] >= 0) {
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
      }
    }
  }
  cout << dp[W] << endl;
  return 0;
}