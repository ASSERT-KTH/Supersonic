#include <iostream>

void cubedNum() {
  using namespace std;
  int inputNum;
  do {
    cin >> inputNum;
  } while (inputNum < 0 || inputNum > 100);
  
  int result = inputNum * inputNum * inputNum;
  
  cout << result << endl;
}

int main() {
  cubedNum();
  return 0;
}