#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

#define MAX_SIZE 101

int m[MAX_SIZE][MAX_SIZE];
int p[MAX_SIZE];

int matrixChainOrder(int n) {
  memset(m, 0, sizeof(m));

  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;
      m[i][j] = INT_MAX;
      for (int k = i; k <= j - 1; k++) {
        int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (m[i][j] > q)
          m[i][j] = q;
      }
    }
  }
  return m[1][n];
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> p[i];
    if (i < n - 1)
      cin >> p[i+1];
  }

  int result = matrixChainOrder(n + 1);
  cout << result << endl;

  return 0;
}