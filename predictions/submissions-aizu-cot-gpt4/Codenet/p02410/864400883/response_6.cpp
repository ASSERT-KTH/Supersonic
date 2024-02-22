#include <iostream>
using namespace std;

int main() {
  int n, m, a[100][100], b[100], c = 0, i, j;
  
  cin >> n >> m;
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  
  for (j = 0; j < m; j++) {
    cin >> b[j];
  }
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      c += a[i][j] * b[j];
    }
    cout << c << '\n';
    c = 0;
  }
  return 0;
}