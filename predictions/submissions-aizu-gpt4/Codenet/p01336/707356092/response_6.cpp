#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
class Data {
public:
  string mName;
  int mC, mV, mD, mL;
  Data(string _n, int _c, int _v, int _d, int _l) : mName(_n), mC(_c), mV(_v), mD(_d), mL(_l) {}
};
int dp[301][3];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  string line;
  stringstream ss;
  while (getline(cin, line)) {
    ss.str(line);
    ss >> N >> M;
    ss.clear();
    vector<Data> idols;
    idols.reserve(N);
    for (int i = 0; i < N; ++i) {
      getline(cin, line);
      string name = line;
      getline(cin, line);
      ss.str(line);
      int C, V, D, L;
      ss >> C >> V >> D >> L;
      ss.clear();
      idols.emplace_back(name, C, V, D, L);
    }
    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), 0);
    for (auto& idol : idols) {
      for (int i = M; i >= idol.mC; --i) {
        dp[i][0] = max(dp[i][0], dp[i-idol.mC][0] + idol.mV);
        dp[i][1] = max(dp[i][1], dp[i-idol.mC][1] + idol.mD);
        dp[i][2] = max(dp[i][2], dp[i-idol.mC][2] + idol.mL);
      }
    }
    int maxv = max({dp[M][0], dp[M][1], dp[M][2]});
    printf("%d\n", maxv);
  }
}