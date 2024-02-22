#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  unsigned long long dp[4001][5];
  unsigned long long prefix[4001][5] = {0};
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 4001; j++)
      dp[j][i] = i == 1 && j <= 1000 ? 1 : 0;
  for (int i = 2; i <= 4; i++)
    #pragma omp parallel for
    for (int j = 0; j <= 4000; j++) {
      prefix[j][i] = (j > 0 ? prefix[j-1][i] : 0) + dp[j][i-1];
      dp[j][i] = (j > 1000 ? prefix[j-1000][i] : prefix[j][i]);
    }
  int n;
  while (cin >> n)
    cout << dp[n][4] << endl;
  return 0;
}