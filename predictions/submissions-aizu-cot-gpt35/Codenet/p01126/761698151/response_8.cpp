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
      int h, p, q;
      cin >> h >> p >> q;
      amida[h * 1000 + p] = 1;
    }

    int current = a;
    int previous = a;

    for (int j = 1000; j > 0; j--) {
      if (amida[current * 1000 + j] == 1) {
        current++;
      } else if (amida[previous * 1000 + j] == 1) {
        current--;
        previous = current;
      }

      if (current == 0 || current == 1000) {
        break;
      }
    }

    cout << current << endl;
  }

  return 0;
}