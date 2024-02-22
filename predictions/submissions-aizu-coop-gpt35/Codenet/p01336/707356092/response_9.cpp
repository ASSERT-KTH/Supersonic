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
const int MAX_N = 1000; // maximum number of idols
Data idols[MAX_N]; // fixed-size array for idols
int main() {
  int N, M;
  string line;
  while (getline(cin, line)) {
    sscanf(line.c_str(), "%d%d", &N, &M); // parse N and M directly
    for (int i = 0; i < N; i++) {
      getline(cin, line);
      string name = line;
      getline(cin, line);
      sscanf(line.c_str(), "%d%d%d%d", &idols[i].mC, &idols[i].mV, &idols[i].mD, &idols[i].mL); // parse idol attributes directly
      idols[i].mName = name;
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < N; j++) {
        int max_val = 0; // calculate maximum value for each idol
        for (int k = 0; k <= 300; k++) {
          if (i - idols[j].mC * k < 0)
            break;
          int val1 = dp[i - idols[j].mC * k][0] + idols[j].mV * k;
          int val2 = dp[i - idols[j].mC * k][1] + idols[j].mD * k;
          int val3 = dp[i - idols[j].mC * k][2] + idols[j].mL * k;
          if (val1 > max_val)
            max_val = val1;
          if (val2 > max_val)
            max_val = val2;
          if (val3 > max_val)
            max_val = val3;
        }
        dp[i][0] = max_val;
        dp[i][1] = max_val;
        dp[i][2] = max_val;
      }
    }
    int maxv = 0;
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < 3; j++) {
        if (dp[i][j] > maxv)
          maxv = dp[i][j];
      }
    }
    printf("%d\n", maxv);
  }
}