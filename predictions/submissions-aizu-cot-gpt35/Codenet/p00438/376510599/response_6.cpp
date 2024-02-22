#include <iostream>

int main() {
  int a, b, n;
  char way[17][17];

  while (std::cin >> a >> b, a || b) {
    std::cin >> n;

    for (int i = 1; i <= b; i++) {
      for (int j = 1; j <= a; j++) {
        way[i][j] = 0;
      }
    }

    for (int i = 0; i < n; i++) {
      int t1, t2;
      std::cin >> t1 >> t2;
      way[t2][t1] = -1;
    }

    for (int i = 1; i <= a; i++) {
      if (way[1][i] == -1) {
        break;
      }
      way[1][i] = 1;
    }

    for (int i = 1; i <= b; i++) {
      if (way[i][1] == -1) {
        break;
      }
      way[i][1] = 1;
    }

    for (int i = 2; i <= b; i++) {
      for (int j = 2; j <= a; j++) {
        if (way[i][j] == 0) {
          int w = 0, h = 0;

          if (way[i][j - 1] != -1) {
            w = way[i][j - 1];
          }

          if (way[i - 1][j] != -1) {
            h = way[i - 1][j];
          }

          way[i][j] = w + h;
        }
      }
    }

    std::cout << static_cast<int>(way[b][a]) << '\n';
  }

  return 0;
}