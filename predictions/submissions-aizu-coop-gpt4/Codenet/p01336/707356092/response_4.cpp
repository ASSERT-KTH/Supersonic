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
Data idols[301]; // changed to array

int main() {
  int N, M;
  string line;
  stringstream ss;
  while (getline(cin, line)) {
    ss << line;
    ss >> N >> M;
    ss.clear();
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
    int maxv = 0; // initialize maxv
    for (int i = 0; i < N; i++) {
      for (int j = idols[i].mC; j <= M; j++) { // start from idols[i].mC
        for (int k = 0; k <= 3; k++) {
          dp[j][k] =
              max(dp[j - idols[i].mC][k] + idols[i].mV * k, dp[j][k]);
          maxv = max(dp[j][k], maxv); // update maxv
        }
      }
    }
    printf("%d\n", maxv);
  }
}