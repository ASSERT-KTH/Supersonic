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
int dp[301][3];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  string line;
  stringstream ss;
  while (getline(cin, line)) {
    ss << line;
    ss >> N >> M;
    ss.clear();
    vector<Data> idols;
    idols.reserve(N);
    for (int i = 0; i < N; i++) {
      getline(cin, line);
      string name = line;
      getline(cin, line);
      ss << line;
      int C, V, D, L;
      ss >> C >> V >> D >> L;
      ss.clear();
      idols.emplace_back(name, C, V, D, L);
    }
    memset(dp, 0, sizeof(dp));
    for (const auto &idol : idols) {
      for (int i = M; i >= idol.mC; --i) {
        dp[i][0] = max(dp[i][0], dp[i - idol.mC][0] + idol.mV);
        dp[i][1] = max(dp[i][1], dp[i - idol.mC][1] + idol.mD);
        dp[i][2] = max(dp[i][2], dp[i - idol.mC][2] + idol.mL);
      }
    }
    int maxv = 0;
    for (int i = 0; i <= M; i++) {
      maxv = max({dp[i][0], dp[i][1], dp[i][2], maxv});
    }
    printf("%d\n", maxv);
  }
}