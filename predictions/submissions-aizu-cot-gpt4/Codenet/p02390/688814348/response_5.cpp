#include <iostream>
using namespace std;
int main(void) {
  int S, mod;
  cin >> S;
  mod = S % 3600;
  cout << S / 3600 << ":" << mod / 60 << ":" << mod % 60 << endl;
}