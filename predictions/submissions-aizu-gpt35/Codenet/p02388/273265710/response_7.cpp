#include <iostream>
using namespace std;
void cubedNum(void) {
  int inputNum;
  cin >> inputNum;
  if ((0 <= inputNum) && (inputNum <= 100)) {
    int result = inputNum * inputNum * inputNum;
    cout << result << endl;
  }
  return;
}
int main(void) {
  cubedNum();
  return 0;
}