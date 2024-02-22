#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

typedef pair<int, int> P;
typedef pair<int, P> PP;

int tx[] = {0, 1, 0, -1};
int ty[] = {-1, 0, 1, 0};

static const double EPS = 1e-8;

short int dp[1000000][5];

int main() {
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int max_i = sqrt(n);
    for (int i = 1; i <= max_i; i++) {
      int i_sq = i * i;
      for (int k = 1; k <= 4; k++) {
        for (int j = n; j >= i_sq; j--) {
          dp[j][k] += dp[j - i_sq][k - 1];
          if (dp[j - i_sq][k - 1] == 0) break;
        }
      }
    }
    int sum = 0;
    for (int k = 1; k <= 4; k++) {
      sum += dp[n][k];
    }
    printf("%d\n", sum);
  }
}