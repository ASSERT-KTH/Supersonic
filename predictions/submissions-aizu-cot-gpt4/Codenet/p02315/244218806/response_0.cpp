#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dp[10001];

int main() {
  int N, W;
  scanf("%d%d", &N, &W);
  vector<int> v(N), w(N);
  for (int i = 0; i < N; i++)
    scanf("%d%d", &v[i], &w[i]);

  for (int i = 0; i < N; i++) {
    for (int j = W; j >= w[i]; j--) {
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
  }
  printf("%d\n", dp[W]);
  return 0;
}