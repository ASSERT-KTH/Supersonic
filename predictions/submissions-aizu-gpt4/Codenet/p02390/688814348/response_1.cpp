#include <iostream>
using namespace std;
int main() {
  int S;
  cin >> S;
  int remainder = S % 3600;
  cout << S / 3600 << ":" << remainder / 60 << ":" << remainder % 60 << endl;
}