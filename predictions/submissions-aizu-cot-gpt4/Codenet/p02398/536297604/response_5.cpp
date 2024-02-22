#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c, t = 0;
  cin >> a >> b >> c;
  
  for (int s = a; s <= b; s++) {
    if (c % s == 0) {
      ++t;
    }
  }

  cout << t << '\n';

  return 0;
}