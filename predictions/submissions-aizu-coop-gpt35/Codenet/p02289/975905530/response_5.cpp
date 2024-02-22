#include <iostream>
#include <queue>
#include <map>

int pop_and_print(std::priority_queue<int>& qu) {
  std::cout << qu.top() << std::endl;
  qu.pop();
  return 0;
}

int main() {
  std::map<std::string, std::function<void(std::priority_queue<int>&)>> actions;
  actions["insert"] = [](std::priority_queue<int>& qu) {
    int inp;
    std::cin >> inp;
    qu.push(inp);
  };

  std::string s;
  std::priority_queue<int> qu;

  while (true) {
    std::cin >> s;
    if (s == "end") {
      break;
    } else {
      actions[s](qu);
      pop_and_print(qu);
    }
  }

  return 0;
}