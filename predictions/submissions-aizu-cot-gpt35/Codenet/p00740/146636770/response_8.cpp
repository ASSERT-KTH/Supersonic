#include <iostream>

int main(void) {
  int stone[50] = {0};

  while (true) {
    int bowl, n, p;
    std::cin >> n >> p;

    if (n == 0 && p == 0) {
      return 0;
    }

    bowl = p;
    int ans = -1;

    for (int i = 0; bowl != 0; i = (i + 1) % n) {
      if (bowl == 0) {
        bowl = bowl + stone[i];
        stone[i] = 0;
      } else {
        stone[i]++;
        bowl--;
        if (bowl == 0 && stone[i] == p) {
          ans = i;
          break;
        }
      }
    }

    std::cout << ans << std::endl;
  }
}