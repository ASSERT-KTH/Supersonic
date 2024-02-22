#include <algorithm>
#include <iostream>
#define INF 1 << 28
using namespace std;
int p[1000001];
int memo[1000001][6];
int memo2[1000001];

void solve2(int n) {
  memo2[0] = 0;
  for(int i = 1; i <= n; i++) {
    int ans = INF;
    for (int j = 0; p[j] <= i && j % 2 == 0; j++)
      ans = min(ans, memo2[i - p[j]] + 1);
    memo2[i] = ans;
  }
}

void solve(int n) {
  for(int i = 0; i <= n; i++) {
    memo[i][0] = (i == 0)? 0 : INF;
    for(int j = 1; j <= min(i, 5); j++) {
      int ans = INF;
      for(int k = 0; p[k] <= i; k++)
        ans = min(ans, memo[i - p[k]][j - 1] + 1);
      memo[i][j] = ans;
    }
  }
}

int main() {
  int n;
  for (int i = 0; i <= 1000000; i++) {
    p[i] = i * (i + 1) * (i + 2) / 6;
    if(p[i] > 1000000) {
      p[i] = -1;
      break;
    }
  }
  while (cin >> n, n) {
    solve(n);
    solve2(n);
    cout << memo[n][5] << " " << memo2[n] << endl;
  }
}