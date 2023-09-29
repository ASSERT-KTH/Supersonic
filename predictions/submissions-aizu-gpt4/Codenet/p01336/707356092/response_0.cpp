#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;
int tx[] = {0, 1, 0, -1};
int ty[] = {-1, 0, 1, 0};
static const double EPS = 1e-8;
class Data {
public:
  int mC, mV, mD, mL;
  Data(int _c, int _v, int _d, int _l) : mC(_c), mV(_v), mD(_d), mL(_l) {}
};
int dp[301][3];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  while (cin >> N >> M) {
    vector<Data> idols;
    for (int i = 0; i < N; i++) {
      string name;
      cin >> name;
      int C, V, D, L;
      cin >> C >> V >> D >> L;
      idols.push_back(Data(C, V, D, L));
    }
    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), 0);
    for (int i = 0; i <= M; i++) {
      for (const auto &idol : idols) {
        for (int k = 0; k * idol.mC <= i; k++) {
          dp[i][0] = max(dp[i - idol.mC * k][0] + idol.mV * k, dp[i][0]);
          dp[i][1] = max(dp[i - idol.mC * k][1] + idol.mD * k, dp[i][1]);
          dp[i][2] = max(dp[i - idol.mC * k][2] + idol.mL * k, dp[i][2]);
        }
      }
    }
    int maxv = 0;
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < 3; j++) {
        maxv = max(dp[i][j], maxv);
      }
    }
    cout << maxv << "\n";
  }
  return 0;
}