#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  
    int n;
    std::cin >> n;
  
    std::vector<int> A(n);
    for (int i = 0; i < n; i++)
        std::cin >> A[i];
  
    std::sort(A.begin(), A.end());
  
    for (int i = 0; i < n; i++)
      std::cout << (i ? " " : "") << A[i];
    std::cout << "\n";
}