#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main() {
  std::string s;
  int inp;
  std::vector<int> qu;
  
  qu.reserve(1000); // Allocate memory in advance

  while (1) {
    std::cin >> s;
    if (s == "end") {
      break;
    } else if (s == "insert") {
      std::cin >> inp;
      qu.push_back(inp);
    }
  }

  std::sort(qu.begin(), qu.end()); // Sort the vector

  // Print and clear the vector
  for (int i = 0; i < qu.size(); i++) {
    std::cout << qu[i] << std::endl;
  }
  qu.clear();

  return 0;
}