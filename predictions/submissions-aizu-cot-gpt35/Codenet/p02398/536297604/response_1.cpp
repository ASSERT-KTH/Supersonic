#include <iostream>
using namespace std;

int main() {
  int a, b, s, t = 0;
  cin >> a >> b;

  for (s = a; s <= b; s++) {
    t += (b / s) - ((a - 1) / s);
  }

  cout << t << endl;
  return 0;
}