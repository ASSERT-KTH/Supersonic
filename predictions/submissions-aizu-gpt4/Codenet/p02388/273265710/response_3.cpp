#include <iostream>
using namespace std;
inline void cubedNum(void) {
  int inputNum = -1;
  while (cin >> inputNum, inputNum < 0 || inputNum > 100);
  cout << inputNum*inputNum*inputNum << endl;
}
int main(void) {
  cubedNum();
  return 0;
}