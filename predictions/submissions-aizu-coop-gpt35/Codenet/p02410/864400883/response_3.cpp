#include <iostream>
using namespace std;

int main() {
  int n, m;
  int x, y;
  int **a, *b;
  int c = 0;

  cin >> n >> m;

  // Dynamic memory allocation for a and b
  a = new int*[n];
  for (int i = 0; i < n; i++) {
    a[i] = new int[m];
  }
  b = new int[m];

  // Input values for a
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> x;
      a[i][j] = x;
    }
  }

  // Input values for b
  for (int j = 0; j < m; j++) {
    cin >> y;
    b[j] = y;
  }

  // Matrix multiplication and output
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c += a[i][j] * b[j];
    }
    cout << c << endl;
    c = 0;
  }

  // Deallocate memory for a and b
  for (int i = 0; i < n; i++) {
    delete[] a[i];
  }
  delete[] a;
  delete[] b;

  return 0;
}