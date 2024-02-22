#include <algorithm>
#include <iostream>
using namespace std;
const int INF = 2000000000;

int main() {
  int n, m;
  cin >> n >> m;
  int c[21];
  int mini[50001];
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }
  sort(c + 1, c + 1 + m);
  memset(mini, INF, sizeof(mini));
  mini[0] = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= n - c[i]; j++) {
      if (mini[j] + 1 < mini[j + c[i]]) {
        mini[j + c[i]] = mini[j] + 1;
      }
    }
  }
  cout << mini[n] << endl;
  return 0;
}