#include <iostream>
using namespace std;
int main(void) {
  int S, remainder;
  cin >> S;
  remainder = S % 3600;
  cout << S / 3600 << ":" << remainder / 60 << ":" << remainder % 60 << endl;
  return 0;
}