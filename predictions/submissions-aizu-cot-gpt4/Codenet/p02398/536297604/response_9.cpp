#include <iostream>
using namespace std;
int main() {
  int a, b, c, t = 0;
  cin >> a >> b >> c;
  for (int s = a; s <= min(b, c / 2); s++) {
    if (c % s == 0) {
      t++;
    }
  }
  cout << t << '\n';
  return 0;
}