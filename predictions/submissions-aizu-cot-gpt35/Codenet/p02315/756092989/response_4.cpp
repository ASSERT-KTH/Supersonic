#include <iostream>
#include <vector>
using namespace std;

int n, W;
int weight[110], value[110];
int dp[10010];

int main() {
  scanf("%d %d", &n, &W);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &value[i], &weight[i]);
  }
  for (int i = 0; i <= W; i++) {
    dp[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int w = W; w >= weight[i]; w--) {
      dp[w] = max(dp[w - weight[i]] + value[i], dp[w]);
    }
  }
  printf("%d\n", dp[W]);
  return 0;
}