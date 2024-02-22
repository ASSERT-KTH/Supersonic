#include <iostream>
using namespace std;
int main() {
  int n, m;
  int x, y, a[100][100], b[100];
  int c = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> x;
      a[i][j] = x;
    }
  }
  for (int j = 0; j < m; j++) {
    cin >> y;
    b[j] = y;
  }
  int unroll_factor = 4, leftover = m % unroll_factor;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m-leftover; j+=unroll_factor) {
      c += a[i][j] * b[j];
      c += a[i][j+1] * b[j+1];
      c += a[i][j+2] * b[j+2];
      c += a[i][j+3] * b[j+3];
    }
    // compute leftover iterations
    for (int j = m-leftover; j < m; j++) {
      c += a[i][j] * b[j];
    }
    cout << c << endl;
    c = 0;
  }
  return 0;
}