#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int INF = 2000000000;

int main() {
  int n, m;
  cin >> n >> m;

  int c[21];
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }

  int mini[n + 1];
  for (int i = 1; i <= n; i++) {
    mini[i] = INF;
  }

  for (int i = 1; i <= m; i++) {
    for (int j = c[i]; j <= n; j++) {
      int temp = mini[j];
      mini[j] = std::min(mini[j], mini[j - c[i]] + 1);
      mini[j - c[i]] = temp;
    }
  }

  cout << mini[n] << endl;
  return 0;
}