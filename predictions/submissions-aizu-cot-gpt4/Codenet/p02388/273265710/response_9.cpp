#include <iostream>
using namespace std;

int cubedNum() {
  int inputNum = -1;
  cin >> inputNum;
  if (inputNum < 0 || inputNum > 100) {
    cout << "Please enter a number between 0 and 100." << endl;
    return -1;
  }
  return inputNum * inputNum * inputNum;
}

int main() {
  int result = cubedNum();
  if (result != -1) {
    cout << result << endl;
  }
  return 0;
}