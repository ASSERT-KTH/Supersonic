#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_COINS = 21;
const int INF = 2000000000;

int main() {
  int m;
  cin >> m;
  
  int c[MAX_COINS];
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }
  
  sort(c + 1, c + m + 1);
  
  int n;
  cin >> n;

  int mini[n + 1];
  for (int i = 1; i <= n; i++) {
    mini[i] = INF;
  }
  
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= n - c[i]; j++) {
      mini[j + c[i]] = min(mini[j] + 1, mini[j + c[i]]);
    }
  }
  
  cout << mini[n] << endl;
  return 0;
}