#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  int x, a[100][100], b[100];
  int c;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int j = 0; j < m; ++j) {
    cin >> b[j];
  }
  for (int i = 0; i < n; ++i) {
    c = 0;
    for (int j = 0; j < m; ++j) {
      c += a[i][j] * b[j];
    }
    cout << c << '\n';
  }
  return 0;
}