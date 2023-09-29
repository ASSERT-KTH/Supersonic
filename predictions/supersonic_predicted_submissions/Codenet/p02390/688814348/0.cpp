#include <iostream>
using namespace std;
int main(void) {
  int S;
  cin >> S;
  cout << S / 1000 << ":" << (S % 1000) / 60 << ":" << (S % 1000) % 60 << endl;
}
