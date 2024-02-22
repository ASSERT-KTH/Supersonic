#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
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
    while (N--) {
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
    int maxv = INT_MIN;
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < idols.size(); j++) {
        for (int k = idols[j].mC; k <= M; k += idols[j].mC) {
          dp[i][0] =
              max(dp[i - idols[j].mC][0] + idols[j].mV, dp[i][0]);
          dp[i][1] =
              max(dp[i - idols[j].mC][1] + idols[j].mD, dp[i][1]);
          dp[i][2] =
              max(dp[i - idols[j].mC][2] + idols[j].mL, dp[i][2]);
        }
      }
      for (int j = 0; j < 3; j++) {
        maxv = max(dp[i][j], maxv);
      }
    }
    printf("%d\n", maxv);
  }
}