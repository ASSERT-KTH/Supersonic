#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, a;
  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    // Vector to hold horizontal lines for each vertical line
    vector<vector<int>> amida(n+1, vector<int>(m+1, 0));
    vector<int> heights(m+1, 0);
    for (int i = 1; i <= m; i++) {
      int h = 0, p = 0, q = 0;
      cin >> h >> p >> q;
      amida[p][h] = i;
      heights[i] = h;
    }
    for (int i = m; i >= 1; i--) {
      if (amida[a][heights[i]] == i)
        a++;
      else if (a > 1 && amida[a - 1][heights[i]] == i)
        a--;
    }
    cout << a << endl;
  }
  return 0;
}