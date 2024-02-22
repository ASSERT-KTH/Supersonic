#include <iostream>
using namespace std;

const int MAX_N = 101;
const int MAX_SUM = 21;
int a[MAX_N];
long long dp[MAX_SUM];

int main() {
  int N;
  cin >> N;
  
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  
  dp[a[1]] = 1;
  for (int i = 2; i <= N; i++) {
    for (int j = 0; j < MAX_SUM; j++) {
      if (j - a[i] >= 0)
        dp[j] += dp[j - a[i]];
      if (j + a[i] < MAX_SUM)
        dp[j] += dp[j + a[i]];
    }
  }
  
  cout << dp[a[N]] << endl;
  return 0;
}