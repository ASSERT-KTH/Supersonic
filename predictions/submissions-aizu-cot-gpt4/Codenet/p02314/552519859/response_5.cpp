#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

int main() {
  int n, m, c[21], mini[50001] = {0};
  fill(mini, mini + 50001, numeric_limits<int>::max());
  
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }
  sort(c + 1, c + m + 1);
  
  mini[0] = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= n - c[i]; j++) {
      mini[j + c[i]] = min(mini[j] + 1, mini[j + c[i]]);
    }
  }
  
  cout << mini[n] << "\n";
  return 0;
}