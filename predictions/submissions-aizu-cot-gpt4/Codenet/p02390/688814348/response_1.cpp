#include <iostream>
using namespace std;
int main(void) {
  int S;
  cin >> S;
  int rem = S % 3600;
  cout << S / 3600 << ":" << rem / 60 << ":" << rem % 60 << endl;
  return 0;
}