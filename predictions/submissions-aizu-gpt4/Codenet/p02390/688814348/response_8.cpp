#include <iostream>
using namespace std;
int main(void) {
  int S, H, M;
  cin >> S;
  H = S / 3600;
  S %= 3600;
  M = S / 60;
  S %= 60;
  cout << H << ":" << M << ":" << S << endl;
}