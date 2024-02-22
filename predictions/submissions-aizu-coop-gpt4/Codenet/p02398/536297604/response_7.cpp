#include <iostream>
using namespace std;

int main() {
  int a, b, c, s, t = 0; // Initialize t to 0

  cin >> a >> b >> c;

  for (s = a; s <= b; s++) {
    // Break the loop early if s is larger than c
    if (s > c) {
      break;
    }

    if (c % s == 0) {
      t++;
    }
  }

  cout << t << endl;

  return 0;
}