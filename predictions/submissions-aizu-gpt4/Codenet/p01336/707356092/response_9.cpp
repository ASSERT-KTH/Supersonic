#define _USE_MATH_DEFINES
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
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
    mName = move(_n);
    mC = _c;
    mV = _v;
    mD = _d;
    mL = _l;
  }
};
int dp[301][3];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  while (cin >> N >> M) {
    vector<Data> idols;
    idols.reserve(N);
    for (int i = 0; i < N; i++) {
      string name;
      cin >> name;
      int C, V, D, L;
      cin >> C >> V >> D >> L;
      idols.emplace_back(move(name), C, V, D, L);
    }
    memset(dp, 0, sizeof(dp));
    for (const auto &idol : idols) {
      for (int i = M; i >= idol.mC; --i) {
        for (int k = 1; k <= 300; k++) {
          if (i - idol.mC * k < 0)
            break;
          dp[i][0] =
              max(dp[i - idol.mC * k][0] + idol.mV * k, dp[i][0]);
          dp[i][1] =
              max(dp[i - idol.mC * k][1] + idol.mD * k, dp[i][1]);
          dp[i][2] =
              max(dp[i - idol.mC * k][2] + idol.mL * k, dp[i][2]);
        }
      }
    }
    int maxv = *max_element(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int));
    printf("%d\n", maxv);
  }
}