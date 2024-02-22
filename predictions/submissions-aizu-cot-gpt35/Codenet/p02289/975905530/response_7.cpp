#include <iostream>
#include <queue>
#include <string>

void pop_and_print(std::priority_queue<int>& qu) {
  std::cout << qu.top() << '\n';
  qu.pop();
}

int main() {
  std::string s;
  int inp;
  std::priority_queue<int> qu;

  while (std::cin >> s && s != "end") {
    if (s == "insert") {
      std::cin >> inp;
      qu.push(inp);
    } else {
      pop_and_print(qu);
    }
  }

  return 0;
}