#include <iostream>
#include <queue>
#include <string>
#include <vector>

int pop_and_print(std::priority_queue<int, std::vector<int>, std::greater<int>> &qu) {
  std::cout << qu.top() << '\n';
  qu.pop();
  return 0;
}

int main() {
  std::string s;
  int inp;
  std::priority_queue<int, std::vector<int>, std::greater<int>> qu;
  while (std::cin >> s) {
    if (s == "end") {
      break;
    } else if (s == "insert") {
      std::cin >> inp;
      qu.push(inp);
    } else {
      pop_and_print(qu);
    }
  }
  return 0;
}