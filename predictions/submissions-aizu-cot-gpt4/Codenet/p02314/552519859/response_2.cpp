#include <cstdio>
#include <iostream>
using namespace std;
const int INF = 2000000000;
int main() {
  int n, m;
  cin >> n >> m;
  int c[21];
  int mini[50001] = {0};
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; i++)
    mini[i] = INF;
  for (int i = 1; i <= m; i++) {
    for (int j = c[i]; j <= n; j++) {
      mini[j] = min(mini[j] + 1, mini[j - c[i]] + 1);
    }
  }
  cout << mini[n] << endl;
  return 0;
}