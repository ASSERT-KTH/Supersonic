#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int N, W;
int w[201];
ll cur[10001][202], nxt[10001][202];
int main() {
  cin >> N >> W;
  for (int i = 0; i < N; i++)
    cin >> w[i];
  for (int j = 0; j < 10001; j++) {
    for (int k = 0; k <= N; k++) {
      if (j <= W && (k == N || w[k] + j > W))
        cur[j][k] = 1;
      else
        cur[j][k] = 0;
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j < 10001; j++) {
      for (int k = 0; k <= i; k++) {
        nxt[j][k] = 0;
        int nmwidx = k;
        if (k == N || w[k] > w[i])
          nmwidx = i;
        nxt[j][k] += cur[j][nmwidx];
        if (j + w[i] <= W)
          nxt[j][k] += cur[j + w[i]][k];
        nxt[j][k] %= mod;
      }
    }
    swap(cur, nxt);
  }
  cout << cur[0][N] << endl;
  return 0;
}