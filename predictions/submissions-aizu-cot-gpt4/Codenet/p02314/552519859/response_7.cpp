#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  const int INF = 2000000000;
  int n, m;
  cin >> n >> m;
  
  vector<int> c(m+1);
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }
  sort(c.begin() + 1, c.end());
  
  vector<int> mini(n+1, INF);
  mini[0] = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= n - c[i]; j++) {
      mini[j + c[i]] = min(mini[j] + 1, mini[j + c[i]]);
    }
  }
  
  cout << mini[n] << endl;
  return 0;
}