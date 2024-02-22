#include <iostream>
#include <limits.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s;
  int inp;
  priority_queue<int> qu;

  // Define the pop_and_print function as a lambda inside main
  auto pop_and_print = [&]() {
    if (!qu.empty()) {
      cout << qu.top() << "\n"; // Use "\n" instead of endl
      qu.pop();
    }
  };

  // Loop as long as there is input to read
  while (cin >> s) {
    if (s == "end") {
      break;
    } else if (s == "insert") {
      cin >> inp;
      qu.push(inp);
    } else {
      pop_and_print();
    }
  }

  return 0;
}