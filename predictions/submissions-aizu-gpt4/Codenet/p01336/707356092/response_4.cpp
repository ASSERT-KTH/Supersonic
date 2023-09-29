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
    mName = move(_n);
    mC = _c;
    mV = _v;
    mD = _d;
    mL = _l;
  }
};
int dp[301][3];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  while (cin >> N >> M) {
    vector<Data> idols;
    idols.reserve(N);
    for (int i = 0; i < N; i++) {
      string name;
      cin >> name;
      int C, V, D, L;
      cin >> C >> V >> D >> L;
      idols.emplace_back(move(name), C, V, D, L);
    }
    memset(dp, 0, sizeof(dp));
    for (const auto& idol : idols) {
      for (int i = idol.mC; i <= M; i++) {
        dp[i][0] = max(dp[i][0], dp[i-idol.mC][0] + idol.mV);
        dp[i][1] = max(dp[i][1], dp[i-idol.mC][1] + idol.mD);
        dp[i][2] = max(dp[i][2], dp[i-idol.mC][2] + idol.mL);
      }
    }
    int maxv = max({dp[M][0], dp[M][1], dp[M][2]});
    printf("%d\n", maxv);
  }
}