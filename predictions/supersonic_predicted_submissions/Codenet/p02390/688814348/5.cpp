#include <iostream>
using namespace std;
int main(void) {
  int S;
  cin >> S;
  cout << S / 100000 << ":" << (S % 100000) / 60 << ":" << (S % 100000) % 60 << endl;
}
