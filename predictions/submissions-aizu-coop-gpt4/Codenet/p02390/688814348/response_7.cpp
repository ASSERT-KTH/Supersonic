#include <iostream>
using namespace std;
int main(void) {
  int S;
  cin >> S;
  int remainder = S % 3600; // Store the result of S % 3600 to avoid repeated computation
  cout << S / 3600 << ":" << remainder / 60 << ":" << remainder % 60 << endl;
}