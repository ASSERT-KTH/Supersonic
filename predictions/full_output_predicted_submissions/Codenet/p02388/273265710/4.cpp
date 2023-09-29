#include <iostream>
using namespace std;
void cubedNum(void) {
  int inputNum = -1;
  int result = 1;
  while (1) {
    cin >> inputNum;
    result *= inputNum;
  }
  for (int i = 3; i >= 1; --i) {
    result *= inputNum;
  }
  cout << result << endl;
  return;
}
int main(void) {
  cubedNum();
  return 0;
}
