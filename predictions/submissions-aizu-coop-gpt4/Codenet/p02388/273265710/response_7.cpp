#include <iostream>
#include <cmath>
using namespace std;

void cubedNum(void) {
  int inputNum = -1;
  while (true) {
    cin >> inputNum;
    if ((0 <= inputNum) && (inputNum <= 100)) {
      break;
    }
  }
  int result = pow(inputNum, 3); // Use pow() to calculate the cube of the number
  cout << result << endl;
  return;
}

int main(void) {
  cubedNum();
  return 0;
}