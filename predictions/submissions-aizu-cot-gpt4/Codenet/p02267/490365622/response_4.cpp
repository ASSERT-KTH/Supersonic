#include <iostream>
#include <unordered_set>

int main() {
  std::ios_base::sync_with_stdio(false);
  
  int n, q, temp, cnt = 0;
  std::unordered_set<int> S;

  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> temp;
    S.insert(temp);
  }

  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    std::cin >> temp;
    if (S.count(temp)) {
      ++cnt;
    }
  }

  std::cout << cnt << "\n";
  return 0;
}