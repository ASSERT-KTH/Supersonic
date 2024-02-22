#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 2000000000;

int main() {
  int n, m;
  cin >> n >> m;

  int c[21];
  int mini[n + 1];
  fill(mini, mini + n + 1, INF);

  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }

  sort(c + 1, c + 1 + m);

  for (int i = 1; i <= m; i++) {
    for (int j = c[i]; j <= n; j++) {
      mini[j] = min(mini[j], mini[j - c[i]] + 1);
    }
  }

  cout << mini[n] << endl;

  return 0;
}