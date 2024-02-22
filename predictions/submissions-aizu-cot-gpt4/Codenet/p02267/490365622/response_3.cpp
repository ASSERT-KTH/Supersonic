#include <iostream>
#include <unordered_set>
int main() {
  int n, q, temp, cnt = 0;
  std::unordered_set<int> S;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> temp;
    S.insert(temp);
  }
  std::cin >> q;
  for (int j = 0; j < q; j++) {
    std::cin >> temp;
    if (S.find(temp) != S.end()) {
      cnt++;
    }
  }
  std::cout << cnt << std::endl;
  return 0;
}