#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;
int tx[] = {0, 1, 0, -1};
int ty[] = {-1, 0, 1, 0};
static const double EPS = 1e-8;

int main() {
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;
    vector<vector<int>> dp(5, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    dp.reserve(n + 1);
    for (int i = 1; i <= n; i++) {
      for (int k = 1; k <= 4; k++) {
        for (int j = i * i; j <= n; j++) {
          dp[k][j] += dp[k - 1][j - i * i];
        }
      }
    }
    printf("%d\n", dp[4][n] + dp[3][n] + dp[2][n] + dp[1][n]);
  }
}