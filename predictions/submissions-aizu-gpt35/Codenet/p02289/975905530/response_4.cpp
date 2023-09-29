#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
  string s;
  int inp;
  priority_queue<int, vector<int>, greater<int>> qu; // Use min heap instead of max heap
  while (cin >> s) { // Use input stream directly in while loop condition
    if (s == "end") {
      break;
    } else if (s == "insert") {
      cin >> inp;
      qu.push(inp);
    } else if (s == "remove") { // Use "remove" instead of "pop_and_print"
      if (!qu.empty()) {
        cout << qu.top() << endl;
        qu.pop();
      }
    }
  }
  return 0;
}