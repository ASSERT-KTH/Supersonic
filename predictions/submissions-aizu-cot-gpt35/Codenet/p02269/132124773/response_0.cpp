#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  
  std::set<std::string> dictionary;
  std::vector<std::string> results;
  
  std::string com, word;
  while (n--) {
    std::cin >> com >> word;
    if (com[0] == 'i')
      dictionary.insert(word);
    else {
      if (dictionary.count(word))
        results.push_back("yes");
      else
        results.push_back("no");
    }
  }
  
  for (const auto& result : results) {
    std::cout << result << std::endl;
  }
  
  return 0;
}