#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int INF = 2000000000;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> c(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }
  sort(c.begin() + 1, c.end());
  vector<int> mini(n + 1, INF);
  mini[0] = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = c[i]; j <= n; j++) {
      mini[j] = min(mini[j], mini[j - c[i]] + 1);
    }
  }
  cout << mini[n] << '\n';
  return 0;
}