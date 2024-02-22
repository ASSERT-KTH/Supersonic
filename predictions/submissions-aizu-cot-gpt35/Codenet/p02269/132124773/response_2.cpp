#include <iostream>
#include <unordered_map>
#include <string>

int main() {
  int n;
  std::cin >> n;
  std::unordered_map<std::string, bool> Dic;
  Dic.reserve(n);
  std::string com, word;
  while (n--) {
    std::cin >> com >> word;
    if (com.front() == 'i')
      Dic[word] = true;
    else {
      if (Dic[word])
        std::cout << "yes" << std::endl;
      else
        std::cout << "no" << std::endl;
    }
  }
}