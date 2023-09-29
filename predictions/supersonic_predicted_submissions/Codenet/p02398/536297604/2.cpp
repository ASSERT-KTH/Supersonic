#include <iostream>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = a; i <= b; i++) {
    if (c % i == 0) {
      t++;
    }
  }
  cout << t << endl;
  return 0;
}
