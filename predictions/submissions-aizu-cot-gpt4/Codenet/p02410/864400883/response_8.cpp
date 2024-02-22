#include <iostream>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int **a = new int*[n];
  for(int i = 0; i < n; ++i)
    a[i] = new int[m];
  int *b = new int[m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }
  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < m; j++) {
      c += a[i][j] * b[j];
    }
    cout << c << endl;
  }
  for(int i = 0; i < n; ++i)
    delete [] a[i];
  delete [] a;
  delete [] b;
  return 0;
}