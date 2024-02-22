#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
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
  while (getline(cin, line)) {
    stringstream ss(line);
    ss >> N >> M;
    vector<Data> idols;
    for (int i = 0; i < N; i++) {
      getline(cin, line);
      string name = line;
      getline(cin, line);
      stringstream ss(line);
      int C, V, D, L;
      ss >> C >> V >> D >> L;
      idols.push_back(Data(name, C, V, D, L));
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < idols.size(); i++) {
        for (int j = idols[i].mC; j <= M; j++) {
          dp[j][0] = max(dp[j - idols[i].mC][0] + idols[i].mV, dp[j][0]);
          dp[j][1] = max(dp[j - idols[i].mC][1] + idols[i].mD, dp[j][1]);
          dp[j][2] = max(dp[j - idols[i].mC][2] + idols[i].mL, dp[j][2]);
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