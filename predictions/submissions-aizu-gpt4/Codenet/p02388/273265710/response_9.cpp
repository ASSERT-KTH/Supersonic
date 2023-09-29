#include <iostream>
using namespace std;

inline void cubedNum() {
  int inputNum = -1;
  while (inputNum < 0 || inputNum > 100) {
    cin >> inputNum;
  }
  cout << inputNum * inputNum * inputNum << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cubedNum();
  return 0;
}