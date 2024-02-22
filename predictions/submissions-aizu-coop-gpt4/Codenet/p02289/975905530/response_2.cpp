#include <iostream>
#include <limits.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int pop_and_print(priority_queue<int> &qu) {
  if(qu.empty()) {
    cout << "The queue is empty." << endl;
    return 0;
  }
  cout << qu.top() << endl;
  qu.pop();
  return 0;
}

int main() {
  string s;
  int inp;
  priority_queue<int> qu;

  // Moved s and inp declaration out of the loop
  while (1) {
    if(!(cin >> s)) {
       cout << "Invalid command. Please try again." << endl;
       cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
       continue;
    }
    
    if (s == "end") {
      break;
    } else if (s == "insert") {
      if(!(cin >> inp)) {
         cout << "Invalid number. Please try again." << endl;
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         continue;
      }
      qu.push(inp);
    } else {
      pop_and_print(qu);
    }
  }
  return 0;
}