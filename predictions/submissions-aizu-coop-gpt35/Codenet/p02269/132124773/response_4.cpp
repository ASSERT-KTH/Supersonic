#include <iostream>
#include <map>
#include <string>

int main() {
  int n;
  std::cin >> n;
  
  std::map<std::string, bool> Dic;
  std::string word;
  
  while (n--) {
    std::string com;
    std::cin >> com >> word;
    
    switch (com[0]) {
      case 'i': {
        auto it = Dic.find(word);
        if (it == Dic.end()) {
          Dic.emplace(word, true);
        }
        break;
      }
      case 's': {
        auto it = Dic.find(word);
        if (it != Dic.end()) {
          std::cout << "yes\n";
        } else {
          std::cout << "no\n";
        }
        break;
      }
    }
  }
  
  return 0;
}