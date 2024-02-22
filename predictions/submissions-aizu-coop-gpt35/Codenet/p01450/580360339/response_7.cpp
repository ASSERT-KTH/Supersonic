#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int N, W;
int w[201];
ll dp[2][10001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> W;
  for (int i = 0; i < N; i++)
    cin >> w[i];

  ll (*cur)[10001] = dp;
  ll (*prev)[10001] = dp + 1;

  // Initialize dp arrays
  for (int j = 0; j <= W; j++) {
    for (int k = 0; k <= N; k++) {
      if (j <= W && (k == N || w[k] + j > W))
        prev[j][k] = 1;
      else
        prev[j][k] = 0;
    }
  }

  for (int i = N - 1; i >= 0; i--) {
    swap(cur, prev);
    for (int j = 0; j <= W; j++) {
      ll sum1 = 0, sum2 = 0;
      for (int k = 0; k <= N; k += 2) {
        int nmwidx1 = k;
        int nmwidx2 = k + 1;
        if (k == N || w[k] > w[i])
          nmwidx1 = i;
        if (k + 1 == N || w[k + 1] > w[i])
          nmwidx2 = i;
        sum1 += cur[j][nmwidx1];
        sum2 += cur[j][nmwidx2];
        if (j + w[i] <= W) {
          sum1 += cur[j + w[i]][k];
          sum2 += cur[j + w[i]][k + 1];
        }
      }
      prev[j][i] = (sum1 + sum2) % mod;
    }
  }

  cout << prev[0][N] << endl;
  return 0;
}