#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, q;
  std::cin >> n;
  
  std::vector<int> S(n);
  for (int i = 0; i < n; i++) {
    std::cin >> S[i];
  }
  
  std::cin >> q;
  
  std::vector<int> T(q);
  for (int i = 0; i < q; i++) {
    std::cin >> T[i];
  }
  
  std::sort(S.begin(), S.end());
  std::sort(T.begin(), T.end());
  
  int C = 0;
  for (int i = 0; i < q; i++) {
    if (std::binary_search(S.begin(), S.end(), T[i])) {
      C++;
    }
  }
  
  std::cout << C << std::endl;
  return 0;
}