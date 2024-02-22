#include <iostream>
#include <unordered_set>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::unordered_set<std::string> Dic;

  std::string com;
  while (n--) {
    std::cin >> com;
    if (com[0] == 'i') {
      std::cin >> com;
      Dic.insert(com);
    } else {
      std::cin >> com;
      if (Dic.count(com))
        std::cout << "yes\n";
      else
        std::cout << "no\n";
    }
  }

  return 0;
}