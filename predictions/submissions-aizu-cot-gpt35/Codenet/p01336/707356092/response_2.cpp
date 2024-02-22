#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static const double EPS = 1e-8;

class Data {
public:
  const std::string& mName;
  int mC, mV, mD, mL;
  Data(const std::string& _n, int _c, int _v, int _d, int _l)
      : mName(_n), mC(_c), mV(_v), mD(_d), mL(_l) {}
};

int dp[301][3];

int main() {
  int N, M;
  std::string line;
  std::stringstream ss;

  while (std::getline(std::cin, line)) {
    ss << line;
    ss >> N >> M;
    ss.clear();

    std::vector<Data> idols;
    idols.reserve(N);

    for (int i = 0; i < N; i++) {
      std::getline(std::cin, line);
      const std::string name = line;
      std::getline(std::cin, line);
      ss << line;
      int C, V, D, L;
      ss >> C >> V >> D >> L;
      ss.clear();
      idols.emplace_back(name, C, V, D, L);
    }

    std::memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= M; i++) {
      for (const auto& idol : idols) {
        for (int k = 0; k <= 300; k++) {
          if (i - idol.mC * k < 0)
            break;
          dp[i][0] = std::max(dp[i - idol.mC * k][0] + idol.mV * k, dp[i][0]);
          dp[i][1] = std::max(dp[i - idol.mC * k][1] + idol.mD * k, dp[i][1]);
          dp[i][2] = std::max(dp[i - idol.mC * k][2] + idol.mL * k, dp[i][2]);
        }
      }
    }

    int maxv = 0;

    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < 3; j++) {
        maxv = std::max(dp[i][j], maxv);
      }
    }

    std::printf("%d\n", maxv);
  }
}