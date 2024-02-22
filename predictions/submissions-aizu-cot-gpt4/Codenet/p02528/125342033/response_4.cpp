#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  
  int n;
  std::cin >> n;
  
  std::vector<int> A(n);
  for (int i = 0; i < n; i++)
    std::cin >> A[i];
    
  std::sort(A.begin(), A.end());
  
  for (int i = 0; i < n; i++)
    std::cout << (i ? " " : "") << A[i];
  std::cout << '\n';
}