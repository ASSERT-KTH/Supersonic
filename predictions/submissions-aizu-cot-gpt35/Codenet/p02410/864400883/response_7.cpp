#include <iostream>
using namespace std;

int main() {
  int n, m;
  int x, y, a[10000], b[100], c[100];
  int index = 0;
  
  cin >> n >> m;
  
  // Read matrix a and calculate dot product
  for (int i = 0; i < n; i++) {
    int rowSum = 0;
    for (int j = 0; j < m; j++) {
      cin >> x;
      a[index++] = x;
      rowSum += x * b[j];
    }
    c[i] = rowSum;
  }
  
  // Read array b
  for (int j = 0; j < m; j++) {
    cin >> y;
    b[j] = y;
  }
  
  // Print the resulting array c
  for (int i = 0; i < n; i++) {
    cout << c[i] << endl;
  }
  
  return 0;
}