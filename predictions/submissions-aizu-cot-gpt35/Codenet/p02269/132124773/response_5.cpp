#include <iostream>
#include <unordered_map>
#include <string>

int main() {
  int n;
  std::cin >> n;
  std::unordered_map<std::string, bool> dictionary;
  std::string command, word;
  while (n--) {
    std::cin >> command >> word;
    if (command == "insert")
      dictionary[word] = true;
    else {
      if (dictionary[word])
        std::cout << "yes\n";
      else
        std::cout << "no\n";
    }
  }
}