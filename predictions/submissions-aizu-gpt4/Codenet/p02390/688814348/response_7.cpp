#include <iostream>
using namespace std;
int main(void) {
  int S;
  cin >> S;
  int hours = S / 3600;
  S %= 3600;
  cout << hours << ":" << S / 60 << ":" << S % 60 << endl;
}