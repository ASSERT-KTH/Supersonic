#include <iostream>
using namespace std;

int main() {
  int64_t a, b, c;
  int64_t t = 0;

  cin >> a >> b >> c;

  for (int64_t s = a; s <= b; s++) {
    if (c % s == 0) {
      t++;
    }
  }

  cout << t << endl;
  return 0;
}