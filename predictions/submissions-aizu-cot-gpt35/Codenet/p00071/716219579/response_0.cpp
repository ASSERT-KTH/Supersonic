#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> V;

int main() {
  int n;
  cin >> n;

  for (int t = 0; t < n; t++) {
    vector<V> M(8, V(8));
    for (int i = 0; i < 8; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < 8; j++) {
        M[i][j] = s[j] - '0';
      }
    }

    int x, y;
    cin >> x >> y;
    x--, y--;

    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    M[y][x] = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 3; j >= 1; j--) {
        int ny = y + moves[i].second * j;
        int nx = x + moves[i].first * j;
        if (M[ny][nx] == 1) {
          M[ny][nx] = 0;
        }
      }
    }

    cout << "Data " << t + 1 << ":" << '\n';
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        cout << M[i][j];
      }
      cout << '\n';
    }
  }

  return 0;
}