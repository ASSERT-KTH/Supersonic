#include <iostream>
#include <queue>
#include <string>
using namespace std;

void pop_and_print(priority_queue<int> &qu) {
  if(!qu.empty()) {
    cout << qu.top() << '\n';
    qu.pop();
  }
}

int main() {
  string command;
  int number;
  priority_queue<int> qu;

  while (true) {
    cin >> command;

    if (command == "end") {
      break;
    } else if (command == "insert") {
      cin >> number;
      qu.push(number);
    } else if (command == "pop") {
      pop_and_print(qu);
    }
  }

  return 0;
}