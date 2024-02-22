#include <iostream>
#include <unordered_map>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::unordered_map<std::string, bool> dictionary;
  dictionary.reserve(n);

  std::string command, word;
  while (n--) {
    std::cin >> command >> word;
    if (command[0] == 'i') {
      dictionary.emplace(word, true);
    } else {
      auto it = dictionary.find(word);
      if (it != dictionary.end()) {
        std::cout << "yes\n";
      } else {
        std::cout << "no\n";
      }
    }
  }

  return 0;
}