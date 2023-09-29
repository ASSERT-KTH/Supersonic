#include <iostream>
#include <queue>
#include <string>
using namespace std;

inline void pop_and_print(priority_queue<int>& qu) {
  cout << qu.top() << '\n';
  qu.pop();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  priority_queue<int> qu;

  while (cin >> s && s != "end") {
    if (s == "insert") {
      int inp;
      if (cin >> inp) qu.push(move(inp)); 
    } else {
      if (!qu.empty()) pop_and_print(qu);
    }
  }

  return 0;
}