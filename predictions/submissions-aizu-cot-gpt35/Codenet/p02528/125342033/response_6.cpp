#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> A(n);
  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  std::sort(A.begin(), A.end());

  for (int i = 0; i < n; i++) {
    std::cout << A[i];
    if (i < n - 1) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;

  return 0;
}