#include <iostream>
#include <queue>
#include <string>
#include <vector>

int pop_and_print(std::vector<int>& qu) {
  std::cout << qu.front() << std::endl;
  std::pop_heap(qu.begin(), qu.end());
  qu.pop_back();
}

int main() {
  std::string s;
  int inp;
  std::vector<int> qu;
  while (1) {
    std::cin >> s;
    if (s == "end") {
      break;
    } else if (s == "insert") {
      std::cin >> inp;
      qu.push_back(inp);
      std::push_heap(qu.begin(), qu.end());
    } else {
      pop_and_print(qu);
    }
  }
  return 0;
}