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
        dictionary.insert(word);
        std::cout << (command[0] == 'i' ? "" : (dictionary.count(word) ? "yes" : "no")) << std::endl;
    }
}