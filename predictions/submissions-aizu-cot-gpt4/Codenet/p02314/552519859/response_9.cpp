#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
  int n, m;
  cin >> n >> m;
  int c[21];
  int mini[50001];
  
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }
  
  sort(c + 1, c + m + 1);
  
  fill(mini, mini + n + 1, INF);
  mini[0] = 0;
  
  for (int i = 1; i <= m; i++) {
    for (int j = c[i]; j <= n; j++) {
      mini[j] = min(mini[j], mini[j - c[i]] + 1);
    }
  }
  
  cout << mini[n] << endl;
  return 0;
}