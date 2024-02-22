#include <iostream>
#include <unordered_set>

int main() {
  int n, q;
  std::cin >> n;

  std::unordered_set<int> S;
  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    S.insert(num);
  }

  std::cin >> q;
  int C = 0;
  for (int i = 0; i < q; i++) {
    int num;
    std::cin >> num;
    if (S.count(num) > 0) {
      C++;
    }
  }

  std::cout << C << std::endl;
  return 0;
}