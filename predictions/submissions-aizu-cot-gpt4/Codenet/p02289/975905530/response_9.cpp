#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int pop_and_return(priority_queue<int> &qu) {
  int top = qu.top();
  qu.pop();
  return top;
}

int main() {
  string s;
  int inp;
  priority_queue<int> qu;
  vector<int> result;
  while (1) {
    cin >> s;
    if (s == "end") {
      break;
    } else if (s == "insert") {
      cin >> inp;
      qu.push(inp);
    } else {
      result.push_back(pop_and_return(qu));
    }
  }

  for (const auto &i : result) {
    cout << i << endl;
  }
  return 0;
}