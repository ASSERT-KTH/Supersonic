#include <iostream>
using namespace std;

int main() {
  int m, a;
  while (true) {
    cin >> m >> a;
    if (m == 0 && a == 0) {
      break;
    }
    int amida[1001] = {0};
    for (int i = 0; i < m; i++) {
      int h = 0, p = 0;
      cin >> h >> p;
      amida[h] = p;
    }
    for (int j = 1000; j > 0; j--) {
      if (amida[j] == 1)
        a++;
      else
        a = amida[j] == a - 1 ? a - 1 : a;
    }
    cout << a << endl;
  }
  return 0;
}