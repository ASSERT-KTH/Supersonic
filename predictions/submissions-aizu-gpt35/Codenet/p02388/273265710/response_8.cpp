#include <iostream>
using namespace std;

void cubedNum(void) {
  int inputNum = -1;
  while (true) {
    cin >> inputNum;
    if ((0 <= inputNum) && (inputNum <= 100)) {
      break;
    }
  }
  int result = inputNum * inputNum * inputNum;
  cout << result << endl;
}

int main() {
  cubedNum();
  return 0;
}