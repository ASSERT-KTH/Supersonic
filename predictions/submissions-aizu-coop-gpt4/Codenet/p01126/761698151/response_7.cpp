#include <iostream>
#include <map>
using namespace std;

int main() {
  int n, m, a;
  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    // Use a map to store only the cells that are updated
    map<pair<int, int>, int> amida;
    for (int i = 0; i < m; i++) {
      int h = 0, p = 0, q = 0;
      cin >> h >> p >> q;
      amida[make_pair(p, h)] = 1;
    }
    // Use a flag to break the loop early when no more updates are possible
    bool updated = false;
    for (int j = 1000; j > 0; j--) {
      // Store the result of the array check to avoid redundant computations
      int check = amida[make_pair(a, j)];
      if (check == 1) {
        a++;
        updated = true;
      } else if (amida[make_pair(a - 1, j)] == 1) {
        a--;
        updated = true;
      }
      // Break the loop early when no more updates are possible
      if (!updated && j < m) {
        break;
      }
    }
    cout << a << endl;
  }
  return 0;
}