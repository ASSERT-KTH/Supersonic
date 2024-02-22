#include <iostream>
#include <queue>
#include <string>

int pop_and_print() {
  std::cout << qu.top() << '\n';
  qu.pop();
  return 0;
}

int main() {
  std::string s;
  int inp;
  std::priority_queue<int> qu;

  while (true) {
    std::cin >> s;
    if (s == "end") {
      break;
    } else if (s == "insert") {
      std::cin >> inp;
      qu.push(inp);
    } else {
      pop_and_print();
    }
  }

  return 0;
}