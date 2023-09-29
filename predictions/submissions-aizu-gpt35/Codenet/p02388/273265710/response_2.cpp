#include <iostream>
using namespace std;

void cubedNum(void) {
  int inputNum = -1;
  while (1) {
    cin >> inputNum;
    if ((0 <= inputNum) && (inputNum <= 100)) {
      break;
    }
  }
  int result = inputNum * inputNum * inputNum;
  cout << result << endl;
  return;
}

int main(void) {
  cubedNum();
  return 0;
}