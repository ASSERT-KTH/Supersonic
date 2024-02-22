#include <iostream>
using namespace std;

int main() {
  int n, m, a;
  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    
    // Use a 2-dimensional array of size nxm
    int amida[101][101] = {{0}};

    for (int i = 0; i < m; i++) {
      int h, p, q;
      cin >> h >> p >> q;
      amida[p][h] = 1;
    }
    
    for (int j = 100; j > 0; j--) {
      if (amida[a][j] == 1) {
        a++;
      }
    }
    cout << a << endl;
  }

  return 0;
}