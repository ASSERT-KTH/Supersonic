#include <iostream>
#include <cmath>
using namespace std;

void cubedNum() {
  int inputNum;
  while (1) {
    cin >> inputNum;
    if (inputNum >= 0 && inputNum <= 100) {
      break;
    }
  }
  int result = pow(inputNum, 3);
  cout << result << endl;
}

int main() {
  cubedNum();
  return 0;
}