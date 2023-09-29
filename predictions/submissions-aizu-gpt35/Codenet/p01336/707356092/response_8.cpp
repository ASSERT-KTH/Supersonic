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
  cout.tie(0);
  int N, M;
  string line;
  stringstream ss;
  while (getline(cin, line)) {
    ss << line;
    ss >> N >> M;
    ss.clear();
    vector<Data> idols;
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
    for (auto const& idol : idols) {
      for (int j = 0; j <= 300; j++) {
        for (int k = 1; k <= M / idol.mC; k++) {
          int cost = idol.mC * k;
          dp[cost][0] = max(dp[cost][0], dp[cost - idol.mC][0] + idol.mV);
          dp[cost][1] = max(dp[cost][1], dp[cost - idol.mC][1] + idol.mD);
          dp[cost][2] = max(dp[cost][2], dp[cost - idol.mC][2] + idol.mL);
        }
      }
    }
    int maxv = 0;
    for (int i = 1; i <= M; i++) {
      for (int j = 0; j < 3; j++) {
        maxv = max(dp[i][j], maxv);
      }
    }
    printf("%d\n", maxv);
  }
}