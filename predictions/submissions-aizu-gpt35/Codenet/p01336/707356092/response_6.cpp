#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int tx[] = {0, 1, 0, -1};
int ty[] = {-1, 0, 1, 0};

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

const int MAX_M = 300;
const int MAX_N = 100;
int dp[MAX_M + 1][3];
vector<Data> idols;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  while (cin >> N >> M) {
    cin.ignore();
    idols.clear();
    for (int i = 0; i < N; i++) {
      string name, line;
      getline(cin, name);
      getline(cin, line);
      stringstream ss(line);
      int C, V, D, L;
      ss >> C >> V >> D >> L;
      idols.emplace_back(name, C, V, D, L);
    }
    memset(dp, 0, sizeof(dp));
    for (const auto& idol : idols) {
      for (int j = 0; j <= MAX_M; j++) {
        for (int k = 1; k <= j / idol.mC; k++) {
          dp[j][0] = max(dp[j - k * idol.mC][0] + k * idol.mV, dp[j][0]);
          dp[j][1] = max(dp[j - k * idol.mC][1] + k * idol.mD, dp[j][1]);
          dp[j][2] = max(dp[j - k * idol.mC][2] + k * idol.mL, dp[j][2]);
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
  return 0;
}