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
#include <stack>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;
int tx[] = {0, 1, 0, -1};
int ty[] = {-1, 0, 1, 0};
static const double EPS = 1e-8;
struct Idol {
  int C, V, D, L;
  Idol(int _c, int _v, int _d, int _l) : C(_c), V(_v), D(_d), L(_l) {}
};
int dp[301][3];
int main() {
  int N, M;
  while (scanf("%d %d", &N, &M) != EOF) {
    vector<Idol> idols;
    for (int i = 0; i < N; i++) {
      int C, V, D, L;
      scanf("%*s %d %d %d %d", &C, &V, &D, &L);
      idols.push_back(Idol(C, V, D, L));
    }
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < idols.size(); j++) {
        int num = min(i / idols[j].C, 300);
        dp[i][0] = max(dp[i - idols[j].C * num][0] + idols[j].V * num, dp[i][0]);
        dp[i][1] = max(dp[i - idols[j].C * num][1] + idols[j].D * num, dp[i][1]);
        dp[i][2] = max(dp[i - idols[j].C * num][2] + idols[j].L * num, dp[i][2]);
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