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
  std::sort(S.begin(), S.end());

  int cnt = 0;
  int q;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    int T;
    std::cin >> T;
    cnt += std::count(S.begin(), S.end(), T);
  }

  std::cout << cnt << std::endl;
  return 0;
}