#include <iostream>
using namespace std;
int main() {
  int a, b, c, t;
  cin >> a >> b >> c;
  for (int s = a; s <= b; s++) {
    if (c % s == 0) {
      t++;
    }
  }
  cout << t << endl;
  return 0;
}
