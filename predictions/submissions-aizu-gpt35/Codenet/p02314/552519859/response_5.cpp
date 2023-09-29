#include <algorithm>
#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
const int INF = 2000000000;
const int MAX_M = 20, MAX_N = 50000;
int main() {
  int n, m;
  cin >> n >> m;
  int c[MAX_M];
  int mini[MAX_N + 1];
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }
  sort(c + 1, c + 1 + m);
  for (int i = 1; i <= n; i++)
    mini[i] = INF;
  for (int i = 1; i <= m; i++) {
    for (int j = c[i]; j <= n; j++) {
      mini[j] = min(mini[j], mini[j - c[i]] + 1);
    }
  }
  cout << mini[n] << endl;
  return 0;
}