#include <iostream>
using namespace std;
int main() {
  long long a, b, c, s, t;
  cin >> a >> b >> c;
  for (long long s = a; s <= b; s++) {
    if (c % s == 0) {
      t++;
    }
  }
  cout << t << endl;
  return 0;
}
