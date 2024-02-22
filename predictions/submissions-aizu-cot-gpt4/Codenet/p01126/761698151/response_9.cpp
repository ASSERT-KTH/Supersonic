#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // C++ I/O operations are tied to C I/O operations by default. This line makes them independent, speeding up I/O operations.
  cin.tie(NULL); // This line unties cin from cout, allowing further speed improvements.

  int n, m, a;
  int amida[101][1001] = {{0}}; // Moving the array outside of the while loop to prevent it from being created for every iteration.

  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    
    for (int i = 0; i < m; i++) {
      int h, p, q; // Removed the initial values of h, p, q because they are never used.
      cin >> h >> p >> q;
      amida[p][h] = 1;
    }

    for (int j = 1000; j > 0; j--) {
      if (amida[a][j] == 1)
        a++;
      else if (amida[a - 1][j] == 1)
        a--;
    }

    cout << a << '\n'; // '\n' is faster than endl because endl forces a flush operation.
  }

  return 0;
}