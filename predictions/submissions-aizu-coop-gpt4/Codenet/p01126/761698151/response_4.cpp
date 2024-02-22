#include <iostream>
using namespace std;
int main() {
  int n, m, a;
  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    int amida[101] = {0}; // Reducing dimension of the array
    int maxH = 0; // Keep track of maximum height
    for (int i = 0; i < m; i++) {
      int h = 0, p = 0, q = 0;
      cin >> h >> p >> q;
      if(h > maxH) // Update the maximum height
          maxH = h;
      amida[p] = q; // Store the move
      amida[q] = p;
    }
    for (int j = maxH; j > 0; j--) { // Only iterate till the maximum height
      if (amida[a] != 0) // If there is a move defined, make the move
        a = amida[a];
    }
    cout << a << endl;
  }
  return 0;
}