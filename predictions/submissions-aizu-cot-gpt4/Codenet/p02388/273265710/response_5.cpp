#include <iostream>
#include <cmath>
using namespace std;

void cubedNum() {
  int inputNum = -1;
  while (1) {
    cin >> inputNum;
    if ((0 <= inputNum) && (inputNum <= 100)) {
      break;
    }
  }
  
  int result = pow(inputNum, 3); // Use pow() function instead of a loop
  cout << result << endl;
  return;
}

int main() {
  cubedNum();
  return 0;
}