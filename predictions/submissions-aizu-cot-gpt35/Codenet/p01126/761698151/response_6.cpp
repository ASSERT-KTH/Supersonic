#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, a;
  do {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }

    // Process the bottom row
    vector<int> verticalLines;
    for (int i = 0; i < m; i++) {
      int h, p, q;
      cin >> h >> p >> q;
      if (h == 1) {
        verticalLines.push_back(p);
      }
    }

    // Simulate the game
    for (int j = 1000; j > 0; j--) {
      if (binary_search(verticalLines.begin(), verticalLines.end(), a)) {
        a++;
      } else if (binary_search(verticalLines.begin(), verticalLines.end(), a - 1)) {
        a--;
      }
    }

    cout << a << endl;
  } while (true);

  return 0;
}