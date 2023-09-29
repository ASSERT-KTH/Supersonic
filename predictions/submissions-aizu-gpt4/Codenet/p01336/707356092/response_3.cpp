#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
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
  cin.tie(0);
  int N, M;
  while (cin >> N >> M) {
    vector<Data> idols;
    idols.reserve(N);
    for (int i = 0; i < N; i++) {
      string name;
      int C, V, D, L;
      cin >> name >> C >> V >> D >> L;
      idols.emplace_back(name, C, V, D, L);
    }
    memset(dp, 0, sizeof(dp));
    for (const auto& idol: idols) {
      for (int i = M; i >= idol.mC; i--) {
        dp[i][0] = max(dp[i][0], dp[i - idol.mC][0] + idol.mV);
        dp[i][1] = max(dp[i][1], dp[i - idol.mC][1] + idol.mD);
        dp[i][2] = max(dp[i][2], dp[i - idol.mC][2] + idol.mL);
      }
    }
    int maxv = *max_element(&dp[0][0], &dp[0][0] + 301*3);
    cout << maxv << '\n';
  }
}