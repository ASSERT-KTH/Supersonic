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
  priority_queue<int, vector<int>, greater<int>> qu;

  while (cin >> s) {
    if (s == "end") break;
    else if (s == "insert") {
      cin >> inp;
      qu.push(inp);
    } else {
      cout << qu.top() << "\n";
      qu.pop();
    }
  }

  return 0;
}