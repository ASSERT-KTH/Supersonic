#include <unordered_set>
#include <string>
#include <iostream>

int main() {
  std::unordered_set<std::string> set;
  int n;
  std::cin >> n;

  while (n--) {
    std::string operation, str;
    std::cin >> operation >> str;

    if (operation == "i")
      set.insert(str);
    else
      std::cout << (set.find(str) != set.end() ? "yes" : "no") << std::endl;
  }

  return 0;
}