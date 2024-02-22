#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  // Dynamically allocate memory for the matrix and vector
  int** a = new int*[n];
  for (int i = 0; i < n; i++) {
    a[i] = new int[m];
  }

  int* b = new int[m];

  // Read the matrix values
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  // Read the vector values
  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }

  // Perform matrix-vector multiplication
  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < m; j++) {
      c += a[i][j] * b[j];
    }
    cout << c << endl;
  }

  // Free the dynamically allocated memory
  for (int i = 0; i < n; i++) {
    delete[] a[i];
  }
  delete[] a;
  delete[] b;

  return 0;
}