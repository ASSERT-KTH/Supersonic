#include <iostream>
using namespace std;

int main() {
  int n, m;
  int* a;
  int* b;
  int c = 0;

  cin >> n >> m;

  // Allocate memory for matrices
  a = new int[n * m];
  b = new int[m];

  // Read input matrices
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i * m + j];
    }
  }

  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }

  // Perform matrix multiplication and print the result
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c += a[i * m + j] * b[j];
    }
    cout << c << endl;
    c = 0;
  }

  // Deallocate memory
  delete[] a;
  delete[] b;

  return 0;
}