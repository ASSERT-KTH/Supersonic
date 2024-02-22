#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

typedef long long ll;

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

int dp[301][3];

int main() {
  int N, M;
  string line;
  stringstream ss;
  while (getline(cin, line)) {
    ss << line;
    ss >> N >> M;
    ss.clear();
    
    Data idols[301]; // Use an array instead of vector
    
    for (int i = 0; i < N; i++) {
      getline(cin, line);
      string name = line;
      getline(cin, line);
      ss << line;
      int C, V, D, L;
      ss >> C >> V >> D >> L;
      ss.clear();
      idols[i] = Data(name, C, V, D, L); // Store idols in the array
    }
    
    memset(dp, 0, sizeof(dp));
    
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < N; j++) { // Iterate over the array of idols
        for (int k = 0; k < 300; k++) { // Simplify the loop condition
          if (i - idols[j].mC * k < 0)
            break;
          int temp = dp[i - idols[j].mC * k][0] + idols[j].mV * k; // Store the result in a temporary variable
          dp[i][0] = max(temp, dp[i][0]); // Assign the value outside the loop
          dp[i][1] = max(dp[i - idols[j].mC * k][1] + idols[j].mD * k, dp[i][1]);
          dp[i][2] = max(dp[i - idols[j].mC * k][2] + idols[j].mL * k, dp[i][2]);
        }
      }
    }
    
    int max_val = 0; // Use a separate variable for maximum value
    
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j < 3; j++) {
        max_val = max(dp[i][j], max_val);
      }
    }
    
    printf("%d\n", max_val);
  }
}