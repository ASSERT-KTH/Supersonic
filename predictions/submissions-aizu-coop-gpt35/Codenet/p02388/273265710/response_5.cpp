#include <iostream>
#include <cmath>

using namespace std;

inline void cubedNum() {
  int inputNum;
  while (true) {
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