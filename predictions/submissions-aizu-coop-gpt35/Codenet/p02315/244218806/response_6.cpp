#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N = 0, W = 0;
  cin >> N >> W;
  vector<int> v, w;
  v.reserve(N);
  w.reserve(N);
  for (int i = 0; i < N; i++) {
    int val, weight;
    cin >> val >> weight;
    v.push_back(val);
    w.push_back(weight);
  }

  vector<int> dp(W + 1, 0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= min(W, j - w[i] + W); j++) {
      if (j - w[i] >= 0) {
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
      }
    }
  }

  cout << dp[W] << endl;
  return 0;
}