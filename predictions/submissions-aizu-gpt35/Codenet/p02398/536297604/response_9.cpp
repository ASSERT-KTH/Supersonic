#include <iostream>
using namespace std;
int main() {
  int a, b, c, s, t=0;
  cin >> a >> b >> c;
  for (s = a; s <= b; s++) {
    if (c % s == 0) {
      t++;
    }
  }
  cout << t << endl;
  return 0;
}