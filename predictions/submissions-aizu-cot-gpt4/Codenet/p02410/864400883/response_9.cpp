#include <iostream>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  int n, m, y, b[100];
  cin >> n >> m;
  for (int j = 0; j < m; j++) {
    cin >> y;
    b[j] = y;
  }
  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < m; j++) {
      int temp;
      cin >> temp;
      c += temp * b[j];
    }
    cout << c << endl;
  }
  return 0;
}