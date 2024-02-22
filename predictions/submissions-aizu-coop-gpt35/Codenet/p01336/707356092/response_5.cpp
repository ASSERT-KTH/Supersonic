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
  string mName;
  int mC, mV, mD, mL;
  Data(string _n, int _c, int _v, int _d, int _l) {
    mName = _n;
    mC = _c;
    mV = _v;
    mD = _d;
    mL = _l;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  string line;
  stringstream ss;
  while (getline(cin, line)) {
    ss << line;
    ss >> N >> M;
    ss.clear();
    Data idols[301];
    for (int i = 1; i <= N; i++) {
      getline(cin, line);
      string name = line;
      getline(cin, line);
      ss << line;
      int C, V, D, L;
      ss >> C >> V >> D >> L;
      ss.clear();
      idols[i] = Data(name, C, V, D, L);
    }
    int dp[2][301][3];
    memset(dp, 0, sizeof(dp[0]));
    for (int i = 0; i <= M; i++) {
      for (const auto& idol : idols) {
        if (i - idol.mC >= 0) {
          dp[i % 2][0] = max(dp[(i - idol.mC) % 2][0] + idol.mV, dp[i % 2][0]);
          dp[i % 2][1] = max(dp[(i - idol.mC) % 2][1] + idol.mD, dp[i % 2][1]);
          dp[i % 2][2] = max(dp[(i - idol.mC) % 2][2] + idol.mL, dp[i % 2][2]);
        }
      }
    }
    int maxv = 0;
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < 3; j++) {
        maxv = max(dp[i % 2][j], maxv);
      }
    }
    printf("%d\n", maxv);
  }
  return 0;
}