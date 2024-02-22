#include <iostream>

int main() {
  int stone[50] = {0};

  while (true) {
    int bowl;
    int n, p;
    std::cin >> n >> p;

    if (n == 0 && p == 0) {
      return 0;
    }

    bowl = p;
    bool flg = true;
    int ans;

    for (int i = 0; flg; i = (i + 1) % n) {
      if (bowl == 0) {
        bowl += stone[i];
        stone[i] = 0;
      } else {
        stone[i]++;
        bowl--;

        if (bowl == 0 && stone[i] == p) {
          ans = i;
          flg = false;
        }
      }
    }

    std::cout << ans << std::endl;
  }
}