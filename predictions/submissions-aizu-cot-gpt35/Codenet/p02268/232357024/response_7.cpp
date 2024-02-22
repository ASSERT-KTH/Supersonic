#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> S(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> S[i];
  }
  
  int cnt = 0;
  int q;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    int T;
    std::cin >> T;
    auto it = std::lower_bound(S.begin(), S.end(), T);
    if (it != S.end() && *it == T) {
      ++cnt;
    }
  }
  
  std::cout << cnt << std::endl;
  return 0;
}