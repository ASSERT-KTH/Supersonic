#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 333;
const int MAX_M = 100005;

int n, m;
int c[MAX_N], v[3][MAX_N];
int dp[MAX_M];

int dpru(int *c, int *v) {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    for (int j = m; j >= c[i]; --j) {
      dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
    }
  }
  return dp[m];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int numTestCases;
  cin >> numTestCases;
  cin.ignore(); // Ignore the newline character
  
  while (numTestCases--) {
    cin >> n >> m;
    cin.ignore(); // Ignore the newline character
    
    for (int i = 0; i < n; ++i) {
      string s;
      getline(cin, s);
      cin >> c[i];
      for (int j = 0; j < 3; ++j) {
        cin >> v[j][i];
      }
      cin.ignore(); // Ignore the newline character
    }
    
    int res = 0;
    for (int i = 0; i < 3; ++i) {
      res = max(res, dpru(c, v[i]));
    }
    cout << res << endl;
  }
  
  return 0;
}