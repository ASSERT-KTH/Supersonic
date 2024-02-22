#include <iostream>
#include <array>

int main(void) {
  const int n = 50;
  std::array<int, n> stone;
  int ans;

  while (true) {
    int p;
    std::cin >> n >> p;

    if (n == 0 && p == 0) {
      break;
    }

    stone.fill(0);

    for (int i = 0; ; i = (i + 1) % n) {
      if (p == 0) {
        p = p + stone[i];
        stone[i] = 0;
      } else {
        stone[i]++;
        p--;
        if (p == 0 && stone[i] == n) {
          ans = i;
          break;
        }
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}