#include <iostream>
using namespace std;
int main() {
  int n, m;
  int x, a[100][100], b[100];
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> x;
      a[i][j] = x;
    }
  }
  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }
  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < m; j++) {
      c += a[i][j] * b[j];
    }
    cout << c << endl;
  }
  return 0;
}