#include <iostream>
#include <queue>
#include <string>
using namespace std;

inline void pop_and_print(priority_queue<int> &qu) {
  cout << qu.top() << '\n';
  qu.pop();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  int inp;
  priority_queue<int> qu;

  while (true) {
    cin >> s;
    if (s == "end") {
      break;
    } else if (s == "insert") {
      cin >> inp;
      qu.push(inp);
    } else if (!qu.empty()) {
      pop_and_print(qu);
    }
  }
  
  return 0;
}