#include <iostream>
using namespace std;

void cubedNum(void) {
  int inputNum;
  do {
    cin >> inputNum;
  } while (inputNum < 0 || inputNum > 100);  // Changed to do-while loop.
  
  int result = inputNum * inputNum * inputNum;  // Removed for loop, directly calculated cube.

  cout << result << endl;
  return;
}

int main(void) {
  cubedNum();
  return 0;
}