#include <iostream>
using namespace std;

void cubedNum() {
  int inputNum;
  cin >> inputNum;
  
  int result = inputNum * inputNum * inputNum;
  
  cout << result << endl;
}

int main() {
  cubedNum();
  return 0;
}