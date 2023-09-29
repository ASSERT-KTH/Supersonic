#include <algorithm>
#include <iostream>
using namespace std;
const int INF = 2000000000;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int c[21];
  int mini[50001] = {0};
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }
  sort(c + 1, c + m + 1);
  fill(mini + 1, mini + n + 1, INF);
  for (int i = 1; i <= m; i++) {
    for (int j = c[i]; j <= n; j++) {
      mini[j] = min(mini[j], mini[j - c[i]] + 1);
    }
  }
  cout << mini[n] << '\n';
  return 0;
}