#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 2000000000;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> c(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }
  vector<int> mini(n + 1, INF);
  mini[0] = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = c[i]; j <= n; j++) {
      mini[j] = min(mini[j], mini[j - c[i]] + 1);
    }
  }
  cout << mini[n] << endl;
  return 0;
}