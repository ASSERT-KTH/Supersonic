#include <iostream>
#include <unordered_set>

int main() {
  int n;
  std::cin >> n;
  std::unordered_set<std::string> Dic;
  std::string com, word;
  while (n--) {
    std::cin >> com >> word;
    if (com[0] == 'i')
      Dic.insert(word);
    else
      std::cout << (Dic.count(word) ? "yes" : "no") << std::endl;
  }
}