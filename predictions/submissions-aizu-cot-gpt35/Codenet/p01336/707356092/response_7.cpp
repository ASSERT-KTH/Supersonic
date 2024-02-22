#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> PP;

static const double EPS = 1e-8;

class Data {
public:
  string mName;
  int mC, mV, mD, mL;
  Data(string _n, int _c, int _v, int _d, int _l)
      : mName(std::move(_n)), mC(_c), mV(_v), mD(_d), mL(_l) {}
};

int dp[301][3];

int main() {
  int N, M;
  string line;
  stringstream ss;
  vector<Data> idols;

  while (getline(cin, line)) {
    ss << line;
    ss >> N >> M;
    ss.clear();

    idols.clear();
    idols.reserve(N);

    for (int i = 0; i < N; i++) {
      getline(cin, line);
      string name = line;
      getline(cin, line);
      ss << line;
      int C, V, D, L;
      ss >> C >> V >> D >> L;
      ss.clear();
      idols.emplace_back(name, C, V, D, L);
    }

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < idols.size(); j++) {
        bool condition = i - idols[j].mC < 0;
        for (int k = 0; !condition && k <= 300; k++) {
          dp[i][0] = max(dp[i - idols[j].mC][0] + idols[j].mV * k, dp[i][0]);
          dp[i][1] = max(dp[i - idols[j].mC][1] + idols[j].mD * k, dp[i][1]);
          dp[i][2] = max(dp[i - idols[j].mC][2] + idols[j].mL * k, dp[i][2]);
          condition = i - idols[j].mC * (k + 1) < 0;
        }
      }
    }

    int maxv = *max_element(&dp[0][0], &dp[M][0] + 1);
    printf("%d\n", maxv);
  }
}