#include <iostream>
using namespace std;

inline int cubedNum() {
  int inputNum = -1;
  while (inputNum < 0 || inputNum > 100) {
    cin >> inputNum;
  }
  return inputNum * inputNum * inputNum;
}

int main() {
  cout << cubedNum() << endl;
  return 0;
}