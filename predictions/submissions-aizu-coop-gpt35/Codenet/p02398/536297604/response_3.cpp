#include <iostream>
using namespace std;

int main() {
  int a, b, c, s, t = 0;
  cin >> a >> b >> c;

  if (a > b) {
    cout << "0" << endl;
    return 0;
  }

  for (s = a; s <= b; s++) {
    int m = (c / s) * s;
    if (m <= b && m == c) {
      t++;
    }
  }

  cout << t << endl;
  return 0;
}