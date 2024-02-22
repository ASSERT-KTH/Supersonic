#include <iostream>
using namespace std;

int main() {
  int n, m;
  int x, y;
  int c = 0;
  scanf("%d%d", &n, &m);

  // Dynamically allocate memory for a
  int** a = new int*[n];
  for (int i = 0; i < n; i++) {
    a[i] = new int[m];
    for (int j = 0; j < m; j++) {
      scanf("%d", &x);
      a[i][j] = x;
    }
  }

  for (int j = 0; j < m; j++) {
    scanf("%d", &y);
    for (int i = 0; i < n; i++) {
      c += a[i][j] * y;
    }
    printf("%d\n", c);
    c = 0;
  }

  // Deallocate memory for a
  for (int i = 0; i < n; i++) {
    delete[] a[i];
  }
  delete[] a;

  return 0;
}