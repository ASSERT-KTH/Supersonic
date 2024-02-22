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
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;
int tx[] = {0, 1, 0, -1};
int ty[] = {-1, 0, 1, 0};
static const double EPS = 1e-8;

class Data {
public:
  const string& mName;
  int mC, mV, mD, mL;
  Data(const string& _n, int _c, int _v, int _d, int _l)
      : mName(_n), mC(_c), mV(_v), mD(_d), mL(_l) {}
};

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
      const string& name = line;
      getline(cin, line);
      ss << line;
      int C, V, D, L;
      ss >> C >> V >> D >> L;
      ss.clear();
      idols.push_back(Data(name, C, V, D, L));
    }
    // Dynamically allocate 2D array
    vector<vector<int>> dp(M + 1, vector<int>(3, 0));

    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < idols.size(); j++) {
        int cTimesK = idols[j].mC * k; // Move the computation outside the loop
        for (int k = 0; k <= 300; k++) {
          if (i - cTimesK < 0)
            break;
          dp[i][0] = max(dp[i - cTimesK][0] + idols[j].mV * k, dp[i][0]);
          dp[i][1] = max(dp[i - cTimesK][1] + idols[j].mD * k, dp[i][1]);
          dp[i][2] = max(dp[i - cTimesK][2] + idols[j].mL * k, dp[i][2]);
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