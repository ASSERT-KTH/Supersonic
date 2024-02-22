#include <iostream>
using namespace std;

int main() {
  int n, m;
  int x, y, a[10000], b[100];
  cin >> n >> m;

  for (int i = 0; i < n * m; i++) {
    cin >> x;
    a[i] = x;
  }

  for (int j = 0; j < m; j++) {
    cin >> y;
    b[j] = y;
  }

  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < m; j++) {
      c += a[i * m + j] * b[j];
    }
    cout << c << endl;
  }

  return 0;
}