#include <iostream>
#include <limits.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;

void pop_and_print(priority_queue<int> &qu) {
  if(!qu.empty()){
    cout << qu.top() << "\n";
    qu.pop();
  }
}

int main() {
  int command, inp;
  priority_queue<int> qu;

  while (cin >> command) {
    switch(command){
        case 0: //Assume 0 is for 'end'
            return 0;
        case 1: //Assume 1 is for 'insert'
            cin >> inp;
            qu.push(inp);
            break;
        default: //Any other number is for 'pop_and_print'
            pop_and_print(qu);
            break;
    }
  }
}
