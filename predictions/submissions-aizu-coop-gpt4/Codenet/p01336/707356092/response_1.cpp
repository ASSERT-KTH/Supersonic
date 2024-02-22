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
      idols.push_back(Data(name, C, V, D, L));
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < idols.size(); j++) {
        for (int k = 0; k <= 300; k++) {
          int remaining = i - idols[j].mC * k;  // Store in a variable for later use
          if (remaining < 0)
            break;
          int temp = dp[remaining][0] + idols[j].mV * k;
          if (dp[i][0] < temp) {
            dp[i][0] = temp;
            break;  // Break early
          }
          temp = dp[remaining][1] + idols[j].mD * k;
          if (dp[i][1] < temp) {
            dp[i][1] = temp;
            break;  // Break early
          }
          temp = dp[remaining][2] + idols[j].mL * k;
          if (dp[i][2] < temp) {
            dp[i][2] = temp;
            break;  // Break early
          }
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