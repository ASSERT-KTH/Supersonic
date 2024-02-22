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
int dp[2][3];
int main() {
  int N, M;
  string line;
  stringstream ss;
  while (getline(cin, line)) {
    ss << line;
    ss >> N >> M;
    ss.clear();
    vector<Data> idols;
    for (int i = 0; i < N; i++) {
      int C, V, D, L;
      cin >> C >> V >> D >> L;
      idols.push_back(Data(C, V, D, L));
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= M; i++) {
      int cur = i & 1;  // current cost index
      for (int j = 0; j < idols.size(); j++) {
        int k = i / idols[j].mC;  // maximum multiples of current idol's cost
        for (int l = 0; l <= k; l++) {
          dp[cur][0] = max(dp[1 - cur][0] + idols[j].mV * l, dp[cur][0]);
          dp[cur][1] = max(dp[1 - cur][1] + idols[j].mD * l, dp[cur][1]);
          dp[cur][2] = max(dp[1 - cur][2] + idols[j].mL * l, dp[cur][2]);
        }
      }
    }
    int maxv = max({dp[M & 1][0], dp[M & 1][1], dp[M & 1][2]});
    printf("%d\n", maxv);
  }
}