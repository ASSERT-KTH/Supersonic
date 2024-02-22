#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;
int tx[] = {0, 1, 0, -1};
int ty[] = {-1, 0, 1, 0};
static const double EPS = 1e-8;
int **dp;
int main() {
  int n;
  while (~scanf("%d", &n)) {
    dp = new int*[n+1];
    for(int i = 0; i <= n; i++){
      dp[i] = new int[5];
    }
    if (n == 0)
      break;
    memset(dp, 0, sizeof(int)*(n+1)*5);
    dp[0][0] = 1;
    for (int i = 1; i * i <= n; i++) {
      for (int k = 1; k <= 4; k++) {
        for (int j = i * i; j <= n; j++) {
          dp[j][k] += dp[j - i * i][k - 1];
        }
      }
    }
    int ans = dp[n][4] + dp[n][3] + dp[n][2] + dp[n][1];
    printf("%d\n", ans);
    for(int i = 0; i <= n; i++){
      delete [] dp[i];
    }
    delete [] dp;
  }
}