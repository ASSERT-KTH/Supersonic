#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void pop_and_print(std::vector<int>& vec) {
  std::cout << vec.back() << '\n';
  vec.pop_back();
}

int main() {
  std::ios_base::sync_with_stdio(false);

  std::string s;
  int inp;
  std::vector<int> vec;

  do {
    std::cin >> s;
    if (s == "end") {
      break;
    } else if (s == "insert") {
      std::cin >> inp;
      vec.push_back(inp);
      std::sort(vec.begin(), vec.end(), std::greater<int>());
    } else {
      pop_and_print(vec);
    }
  } while (true);

  return 0;
}