#include <iostream>
using namespace std;
int main(void) {
  int S;
  cin >> S;
  int hh = S / 3600;
  S %= 3600;
  int mm = S / 60;
  int ss = S % 60;
  cout << hh << ":" << mm << ":" << ss << endl;
}