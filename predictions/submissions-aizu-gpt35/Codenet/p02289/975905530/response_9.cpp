#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  int inp;
  priority_queue<int> qu;

  while (cin >> s) {
    if (s == "end") {
      break;
    } else if (s == "insert") {
      cin >> inp;
      qu.push(inp);
    } else {
      cout << qu.top() << endl;
      qu.pop();
    }
  }

  return 0;
}