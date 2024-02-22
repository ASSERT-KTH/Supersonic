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
int dp[1000000];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i * i <= n; i++) {
      int square = i * i; // calculate square once per iteration
      for (int k = 4; k >= 1; k--) { // reverse order to prevent overwriting
        for (int j = square; j <= n; j++) {
          dp[j] += dp[j - square]; // use 1D array
        }
      }
    }
    printf("%d\n", dp[n]);
  }
}