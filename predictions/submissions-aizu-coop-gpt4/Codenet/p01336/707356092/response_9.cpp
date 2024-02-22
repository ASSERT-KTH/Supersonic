#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

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
  while (scanf("%d %d", &N, &M) != EOF) {
    vector<Data> idols;
    for (int i = 0; i < N; i++) {
      char name[20];
      int C, V, D, L;
      scanf("%s %d %d %d %d", name, &C, &V, &D, &L);
      idols.push_back(Data(name, C, V, D, L));
    }
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < idols.size(); j++) {
        for (int k = 0; k <= idols[j].mC; k++) {
          if (i - idols[j].mC * k < 0)
            break;
          int v = dp[i - idols[j].mC * k][0] + idols[j].mV * k;
          int d = dp[i - idols[j].mC * k][1] + idols[j].mD * k;
          int l = dp[i - idols[j].mC * k][2] + idols[j].mL * k;
          dp[i][0] = max(dp[i][0], v);
          dp[i][1] = max(dp[i][1], d);
          dp[i][2] = max(dp[i][2], l);
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