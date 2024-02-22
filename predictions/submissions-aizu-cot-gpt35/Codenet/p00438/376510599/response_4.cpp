#include <iostream>
using namespace std;

int main() {
  int a, b, n, way[17][17];
  while (cin >> a >> b, a || b) {
    cin >> n;
    for (int i = 1; i <= b; i++) {
      for (int j = 1; j <= a; j++)
        way[i][j] = -1;
    }
    for (int i = 0; i < n; i++) {
      int t1, t2;
      cin >> t1 >> t2;
      way[t2][t1] = 0;
    }
    for (int i = 1; i <= a; i++) {
      if (way[1][i] == -1)
        break;
      way[1][i] = 1;
    }
    for (int i = 2; i <= b; i++) {
      if (way[i][1] == -1)
        break;
      way[i][1] = 1;
    }
    for (int i = 2; i <= b; i++) {
      for (int j = 2; j <= a; j++) {
        if (way[i][j] == -1)
          continue;
        int w = way[i][j - 1];
        int h = way[i - 1][j];
        way[i][j] = w + h;
      }
    }
    cout << way[b][a] << endl;
  }
  return 0;
}