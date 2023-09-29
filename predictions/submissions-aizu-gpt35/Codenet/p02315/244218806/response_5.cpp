#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 1001;
const int MAX_W = 10001;
int dp[MAX_W];
int main() {
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