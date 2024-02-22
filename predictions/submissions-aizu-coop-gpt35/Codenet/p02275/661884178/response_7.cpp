#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  
  int min = 2000000;
  int t;
  std::vector<int> A(10001, 0);
  
  for (int i = 0; i < n; i++) {
    std::cin >> t;
    min = std::min(min, t);
    A[t]++;
  }
  
  std::cout << min;
  for (int i = min; i < 10001; i++) {
    for (int j = 0; j < A[i]; j++) {
      std::cout << ' ' << i;
    }
  }
  std::cout << "\n";
  
  return 0;
}