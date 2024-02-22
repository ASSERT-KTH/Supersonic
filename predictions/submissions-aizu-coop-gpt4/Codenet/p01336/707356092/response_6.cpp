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
  Data() {}
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
    Data idols[100]; // replaced vector with array
    for (int i = 0; i < N; i++) {
      getline(cin, line);
      string name = line;
      getline(cin, line);
      ss << line;
      int C, V, D, L;
      ss >> C >> V >> D >> L;
      ss.clear();
      idols[i] = Data(name, C, V, D, L);
    }
    memset(dp, 0, sizeof(dp));
    int maxv = 0; // variable to store the maximum value
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < N; j++) { // replaced idols.size() with N
        int max_k = i / idols[j].mC; // calculate the maximum number of this idol that can be taken
        for (int k = 0; k <= max_k; k++) {
          dp[i][0] =
              max(dp[i - idols[j].mC * k][0] + idols[j].mV * k, dp[i][0]);
          dp[i][1] =
              max(dp[i - idols[j].mC * k][1] + idols[j].mD * k, dp[i][1]);
          dp[i][2] =
              max(dp[i - idols[j].mC * k][2] + idols[j].mL * k, dp[i][2]);
        }
        // updating the maximum value
        maxv = max(maxv, max(dp[i][0], max(dp[i][1], dp[i][2])));
      }
    }
    printf("%d\n", maxv);
  }
}