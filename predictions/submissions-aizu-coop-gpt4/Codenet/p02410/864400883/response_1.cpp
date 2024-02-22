#include <iostream>
using namespace std;

int main() {
  int n, m;
  int x, y, b[100];
  int c = 0;
  cin >> n >> m;

  // Read vector b
  for (int j = 0; j < m; j++) {
    cin >> y;
    b[j] = y;
  }

  // Read matrix a and perform multiplication immediately
  for (int i = 0; i < n; i++) {
    c = 0;
    for (int j = 0; j < m; j++) {
      cin >> x;
      c += x * b[j];
    }
    cout << c << endl;
  }

  return 0;
}