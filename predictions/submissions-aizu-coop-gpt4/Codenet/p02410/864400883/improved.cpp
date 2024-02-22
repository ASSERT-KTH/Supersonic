#include <iostream>
using namespace std;
int main() {
  int n, m;
  int A[100][100], B[100];
  int x, y;
  int c;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> x;
      A[i][j] = x;
    }
  }
  for (int j = 0; j < m; j++) {
    cin >> y;
    B[j] = y;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c += A[i][j] * B[j];
    }
    cout << c << endl;
    c = 0;
  }
  return 0;
}
