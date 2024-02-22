#include <iostream>
using namespace std;
inline void cubedNum() {
  int inputNum;
  while (true) {
    cin >> inputNum;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }
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