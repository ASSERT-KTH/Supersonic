#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
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
    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
      dp[i] = new int[5];
      memset(dp[i], 0, sizeof(int) * 5);
    }
    dp[0][0] = 1;
    for (int i = 1; i * i <= n; i++) {
      int square = i * i;
      for (int k = 1; k <= 4; k++) {
        for (int j = square; j <= n; j++) {
          dp[j][k] += dp[j - square][k - 1];
        }
      }
    }
    printf("%d\n", dp[n][4] + dp[n][3] + dp[n][2] + dp[n][1]);

    for (int i = 0; i <= n; i++) {
      delete[] dp[i];
    }
    delete[] dp;
  }
}