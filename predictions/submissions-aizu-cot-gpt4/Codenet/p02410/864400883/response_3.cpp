#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  int x, y, b[100];
  cin >> n >> m;
  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }
  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < m; j++) {
      cin >> x;
      c += x * b[j];
    }
    cout << c << "\n";
  }
  return 0;
}