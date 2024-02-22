#include <iostream>
using namespace std;

int main() {
  int n, m;
  
  cin >> n >> m;

  // dynamically allocate memory for the matrix and vector
  int** a = new int*[n];
  for(int i = 0; i < n; ++i)
    a[i] = new int[m];
  int* b = new int[m];

  int c = 0;

  // read the matrix and vector from the user
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }

  // compute and print the result
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c += a[i][j] * b[j];
    }
    cout << c << endl;
    c = 0;
  }

  // deallocate the memory we allocated earlier
  for(int i = 0; i < n; ++i)
    delete [] a[i];
  delete [] a;
  delete [] b;

  return 0;
}