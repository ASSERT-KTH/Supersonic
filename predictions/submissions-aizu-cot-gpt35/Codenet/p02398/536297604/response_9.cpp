#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  int t = 0;
  scanf("%d %d %d", &a, &b, &c);

  for (int s = a; s < b; s++) {
    if (c % s == 0) {
      t++;
    }
  }

  cout << t << endl;
  return 0;
}