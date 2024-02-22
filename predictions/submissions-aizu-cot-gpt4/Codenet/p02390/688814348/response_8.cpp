#include <iostream>
using namespace std;
int main(void) {
  int S;
  cin >> S;
  int mod = S % 3600;
  int hours = S / 3600;
  cout << hours << ":" << mod / 60 << ":" << mod % 60 << endl;
}