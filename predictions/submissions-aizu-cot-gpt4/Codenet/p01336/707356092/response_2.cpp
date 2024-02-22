#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#define INF 0x3f3f3f3f

typedef long long ll;
typedef std::pair<int, int> P;
typedef std::pair<int, P> PP;
int tx[] = {0, 1, 0, -1};
int ty[] = {-1, 0, 1, 0};
static const double EPS = 1e-8;

class Data {
public:
  std::string mName;
  int mC, mV, mD, mL;
  Data(std::string _n, int _c, int _v, int _d, int _l) {
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
  std::string line;
  std::stringstream ss;
  while (getline(std::cin, line)) {
    ss << line;
    ss >> N >> M;
    ss.clear();
    std::vector<Data> idols;
    idols.reserve(N);
    for (int i = 0; i < N; i++) {
      getline(std::cin, line);
      std::string name = line;
      getline(std::cin, line);
      ss << line;
      int C, V, D, L;
      ss >> C >> V >> D >> L;
      ss.clear();
      idols.push_back(Data(name, C, V, D, L));
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < static_cast<int>(idols.size()); j++) {
        for (int k = 0; k <= 300; k++) {
          if (i - idols[j].mC * k < 0)
            break;
          dp[i][0] =
              std::max(dp[i - idols[j].mC * k][0] + idols[j].mV * k, dp[i][0]);
          dp[i][1] =
              std::max(dp[i - idols[j].mC * k][1] + idols[j].mD * k, dp[i][1]);
          dp[i][2] =
              std::max(dp[i - idols[j].mC * k][2] + idols[j].mL * k, dp[i][2]);
        }
      }
    }
    int maxv = 0;
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < 3; j++) {
        maxv = std::max(dp[i][j], maxv);
      }
    }
    printf("%d\n", maxv);
  }
}