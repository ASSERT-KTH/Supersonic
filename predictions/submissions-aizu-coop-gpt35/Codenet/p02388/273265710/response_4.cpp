#include <iostream>
using namespace std;

void cubedNum(void) {
  unsigned char inputNum = 0;
  unsigned char result = 1;

  do {
    cin >> inputNum;
  } while (inputNum > 100);

  result = inputNum * inputNum * inputNum;

  cout << static_cast<int>(result) << endl;
}

int main(void) {
  cubedNum();
  return 0;
}