#include <iostream>
using namespace std;

void cubedNum() {
  int inputNum = -1;
  while (1) {
    cin >> inputNum;
    if ((0 <= inputNum) && (inputNum <= 100)) {
      break;
    }
  }
  // Calculate the cube directly without a loop.
  int result = inputNum * inputNum * inputNum;
  cout << result << endl;
}

int main() {
  cubedNum();
  return 0;
}