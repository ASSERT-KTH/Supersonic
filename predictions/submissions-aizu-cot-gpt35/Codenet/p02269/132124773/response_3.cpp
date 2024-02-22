#include <unordered_map>
#include <iostream>
int main() {
  int n;
  std::cin >> n;
  std::unordered_map<std::string, bool> Dic;
  while (n--) {
    std::string command, word;
    std::cin >> command >> word;
    if (command[0] == 'i')
      Dic.emplace(word, true);
    else {
      if (Dic[word])
        std::cout << "yes" << std::endl;
      else
        std::cout << "no" << std::endl;
    }
  }
}