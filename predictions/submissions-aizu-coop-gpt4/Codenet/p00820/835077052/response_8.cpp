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
    int dp[n+1][4]; // Changed size of dp array
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int sum = 0; // Variable to calculate sum of dp values
    for (int i = 1; i * i <= n; i++) {
      for (int k = 1; k <= 4; k++) {
        for (int j = i * i; j <= n; j++) {
          sum += dp[j - i * i][k - 1]; // Add to sum directly, no need to store in dp[j][k]
        }
      }
    }
    printf("%d\n", sum);
  }
}