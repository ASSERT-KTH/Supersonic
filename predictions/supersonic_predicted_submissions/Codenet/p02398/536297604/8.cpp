#include <iostream>
using namespace std;
int main() {
  long long a, b, c, s, t;
  cin >> a >> b >> c;
  for (int i = a; i <= b; i++) {
    if (c % s == 0) {
      t++;
    }
  }
  cout << t << endl;
  return 0;
}
