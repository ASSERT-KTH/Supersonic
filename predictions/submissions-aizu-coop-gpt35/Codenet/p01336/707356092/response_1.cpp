#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;

static const double EPS = 1e-8;

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

int main() {
  int N, M;
  string line;
  while (getline(cin, line)) {
    stringstream ss(line);
    ss >> N >> M;
    ss.clear();
    
    Data idols[N];
    for (int i = 0; i < N; i++) {
      getline(cin, line);
      string name = line;
      getline(cin, line);
      int C, V, D, L;
      sscanf(line.c_str(), "%d %d %d %d", &C, &V, &D, &L);
      idols[i] = Data(name, C, V, D, L);
    }
    
    int dp[M + 1][3] = {0};
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < N; j++) {
        int val = idols[j].mC;
        for (int k = 0; k <= 300; k++) {
          if (i - val * k < 0)
            break;
          int prev = dp[i - val * k][0];
          dp[i][0] = max(prev + idols[j].mV * k, dp[i][0]);
          dp[i][1] = max(prev + idols[j].mD * k, dp[i][1]);
          dp[i][2] = max(prev + idols[j].mL * k, dp[i][2]);
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