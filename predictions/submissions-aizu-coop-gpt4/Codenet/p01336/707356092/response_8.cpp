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
#include <vector>  // Added this line
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
vector<vector<int>> dp;  // Changed this line
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
    dp = vector<vector<int>>(M+1, vector<int>(3, 0));  // Changed this line
    int maxv = 0;  // Moved this line
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < idols.size(); j++) {
        for (int k = 0; k <= 300; k++) {
          int cost = idols[j].mC * k;  // Added this line
          if (i - cost < 0)
            break;
          int val = dp[i - cost][0] + idols[j].mV * k;  // Changed this line
          int dmg = dp[i - cost][1] + idols[j].mD * k;  // Changed this line
          int luck = dp[i - cost][2] + idols[j].mL * k;  // Changed this line
          dp[i][0] = max(val, dp[i][0]);
          dp[i][1] = max(dmg, dp[i][1]);
          dp[i][2] = max(luck, dp[i][2]);
          maxv = max(maxv, max(val, max(dmg, luck)));  // Added this line
        }
      }
    }
    printf("%d\n", maxv);
  }
}