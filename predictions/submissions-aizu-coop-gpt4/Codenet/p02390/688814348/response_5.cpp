#include <iostream>
using namespace std;
int main(void) {
  int S;
  cin >> S;
  int S_mod = S % 3600; // calculate S % 3600 once and store it in variable
  cout << S / 3600 << ":" << S_mod / 60 << ":" << S_mod % 60 << endl;
}