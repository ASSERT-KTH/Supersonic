#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s;
  int inp;
  priority_queue<int> qu;
  unordered_map<string, int> commandMap = {{"end", 0}, {"insert", 1}};

  while (1) {
    cin >> s;
    switch(commandMap[s]){
      case 0: // end
        return 0;
      case 1: // insert
        cin >> inp;
        qu.push(inp);
        break;
      default: // print and pop
        cout << qu.top() << '\n';
        qu.pop();
    }
  }
  return 0;
}