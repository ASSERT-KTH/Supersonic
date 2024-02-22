#include <iostream>
#include <cstdint>
using namespace std;

void cubedNum(void) {
  int32_t inputNum = -1;
  while (1) {
    cin >> inputNum;
    if ((0 <= inputNum) && (inputNum <= 100)) {
      break;
    }
  }

  // we directly cube inputNum, no need for a loop
  int32_t result = inputNum * inputNum * inputNum;
  cout << result << endl;

  return;
}

int main(void) {
  cubedNum();
  return 0;
}