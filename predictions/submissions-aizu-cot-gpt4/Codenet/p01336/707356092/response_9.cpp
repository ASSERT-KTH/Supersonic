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
int dp[301][3];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  while (cin >> N >> M) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++) {
      string name;
      int C, V, D, L;
      cin >> name >> C >> V >> D >> L;
      for (int j = C; j <= M; j++) {
        int k = min(j / C, 300);
        dp[j][0] = max(dp[j - C * k][0] + V * k, dp[j][0]);
        dp[j][1] = max(dp[j - C * k][1] + D * k, dp[j][1]);
        dp[j][2] = max(dp[j - C * k][2] + L * k, dp[j][2]);
      }
    }
    int maxv = 0;
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < 3; j++) {
        maxv = max(dp[i][j], maxv);
      }
    }
    printf("%d\n", maxv);
  }
}