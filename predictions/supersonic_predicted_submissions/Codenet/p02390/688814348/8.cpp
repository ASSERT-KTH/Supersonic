#include <iostream>
using namespace std;
int main(void) {
  int S;
  cin >> S;
  cout << S / 3600 << ":" << (S - 1) / 60 << ":" << (S - 1) % 60 << endl;
}
