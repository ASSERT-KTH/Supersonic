#include <iostream>
using namespace std;
inline void cubedNum() {
  int inputNum = -1;
  while (!(0 <= inputNum && inputNum <= 100)) {
    cin >> inputNum;
  }
  cout << inputNum * inputNum * inputNum << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cubedNum();
  return 0;
}