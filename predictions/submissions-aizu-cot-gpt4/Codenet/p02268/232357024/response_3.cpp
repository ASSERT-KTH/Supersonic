#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  std::cin >> n;

  std::vector<int> S(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> S[i];
  }

  int cnt = 0;
  int q;
  std::cin >> q;
  int T;
  for (int i = 0; i < q; ++i) {
    std::cin >> T;
    if(std::binary_search(S.begin(), S.end(), T))
      ++cnt;
  }
  std::cout << cnt << "\n";
  return 0;
}