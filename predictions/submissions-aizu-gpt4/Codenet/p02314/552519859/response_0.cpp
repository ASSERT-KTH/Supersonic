#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 2000000000;
int c[21], mini[50001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }

  fill(mini, mini+n+1, INF);
  mini[0] = 0;
  
  sort(c + 1, c + m + 1);

  for (int i = 1; i <= m; i++) {
    for (int j = c[i]; j <= n; j++) {
      mini[j] = min(mini[j], mini[j - c[i]] + 1);
    }
  }

  cout << mini[n] << "\n";
  return 0;
}