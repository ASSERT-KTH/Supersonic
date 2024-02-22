#include <iostream>
#include <unordered_set>
#include <string>

int main() {
  int n;
  std::cin >> n;
  std::unordered_set<std::string> dictionary;
  
  std::string command, word;
  while (n--) {
    std::cin >> command >> word;
    if (command[0] == 'i')
      dictionary.insert(word);
    else {
      if (dictionary.count(word) > 0)
        std::cout << "yes" << std::endl;
      else
        std::cout << "no" << std::endl;
    }
  }
}