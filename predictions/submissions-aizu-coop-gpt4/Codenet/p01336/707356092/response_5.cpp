#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Data {
public:
  int mC, mV, mD, mL;
  Data(int _c, int _v, int _d, int _l) {
    mC = _c;
    mV = _v;
    mD = _d;
    mL = _l;
  }
};

int dp[301][3];

int main() {
  ios_base::sync_with_stdio(false); // Fast I/O
  cin.tie(NULL);

  int N, M;
  while (cin >> N >> M) {
    vector<Data> idols;
    for (int i = 0; i < N; i++) {
      int C, V, D, L;
      cin >> C >> V >> D >> L;
      idols.push_back(Data(C, V, D, L));
    }
    memset(dp, 0, sizeof(dp));
    for (int j = 0; j < N; j++) {
      for (int i = idols[j].mC; i <= M; i++) {
        int k = i / idols[j].mC;
        dp[i][0] = max(dp[i][0], dp[i - idols[j].mC * k] + idols[j].mV * k);
        dp[i][1] = max(dp[i][1], dp[i - idols[j].mC * k] + idols[j].mD * k);
        dp[i][2] = max(dp[i][2], dp[i - idols[j].mC * k] + idols[j].mL * k);
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