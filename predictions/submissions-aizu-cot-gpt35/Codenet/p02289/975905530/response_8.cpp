#include <iostream>
#include <queue>
#include <string>

int pop_and_print(std::priority_queue<int>& qu) {
  std::cout << qu.top() << "\n";
  qu.pop();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  
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
      pop_and_print(qu);
    }
  }
  
  return 0;
}