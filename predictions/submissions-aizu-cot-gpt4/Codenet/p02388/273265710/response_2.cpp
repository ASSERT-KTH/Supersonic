#include <iostream>
using namespace std;

int cubedNum(int inputNum) {
  return inputNum * inputNum * inputNum;
}

int main(void) {
  int inputNum = -1;
  
  while (true) {
    cin >> inputNum;
    if ((0 <= inputNum) && (inputNum <= 100)) {
      break;
    }
  }
  
  int result = cubedNum(inputNum);
  cout << result << endl;
  
  return 0;
}