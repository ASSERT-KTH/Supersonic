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
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
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
class Data {
public:
  int mC, mV, mD, mL;
  Data(int _c, int _v, int _d, int _l) {
    mC = _c;
    mV = _v;
    mD = _d;
    mL = _l;
  }
};
int dp[301][3];
int main() {
  int N, M;
  while (scanf("%d %d", &N, &M) != EOF) {
    Data idols[100];
    for (int i = 0; i < N; i++) {
      int C, V, D, L;
      scanf("%*s %d %d %d %d", &C, &V, &D, &L);
      idols[i] = Data(C, V, D, L);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < N; j++) {
        for (int k = 0; k <= 300; k++) {
          if (i - idols[j].mC * k < 0)
            break;
          dp[i][0] =
              max(dp[i - idols[j].mC * k][0] + idols[j].mV * k, dp[i][0]);
          dp[i][1] =
              max(dp[i - idols[j].mC * k][1] + idols[j].mD * k, dp[i][1]);
          dp[i][2] =
              max(dp[i - idols[j].mC * k][2] + idols[j].mL * k, dp[i][2]);
        }
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