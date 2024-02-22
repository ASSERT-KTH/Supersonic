#include <iostream>
using namespace std;
int main() {
  int a, b, c, t = 0;
  cin >> a >> b >> c;
  if(c >= a) {
    for (int s = a; s <= min(b, c); s++) {
      if (c % s == 0) {
        t++;
      }
    }
  }
  cout << t << endl;
  return 0;
}