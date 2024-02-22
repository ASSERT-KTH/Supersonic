#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
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
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  while (cin >> N >> M) {
    vector<Data> idols;
    for (int i = 0; i < N; i++) {
      string name;
      cin >> name;
      int C, V, D, L;
      cin >> C >> V >> D >> L;
      idols.push_back(Data(name, C, V, D, L));
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < idols.size(); j++) {
        for (int k = 0; k <= 300; k++) {
          if (i - idols[j].mC * k < 0)
            break;
          dp[i][0] =
              max(dp[i - idols[j].mC * k][0] + idols[j].mV * k, dp[i][0]);
          dp[i][1] =
              max(dp[i - idols[j].mC * k][1] + idols[j].mD * k, dp[i][1]);
          dp[i][2] =
              max(dp[i - idols[j].mC * k][2] + idols[j].mL * k, dp[i][2]);
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