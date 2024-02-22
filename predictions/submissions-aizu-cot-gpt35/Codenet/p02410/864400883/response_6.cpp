#include <iostream>

int main() {
  int n, m;
  int a[100][100], b[100];
  
  std::cin >> n >> m;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }
  
  for (int j = 0; j < m; j++) {
    std::cin >> b[j];
  }
  
  for (int i = 0; i < n; i++) {
    int result = 0;
    for (int j = 0; j < m; j++) {
      result += a[i][j] * b[j];
    }
    std::cout << result << std::endl;
  }
  
  return 0;
}