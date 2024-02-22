#include <iostream>

int main(void) {
  int stone[50];
  int n, p;

  while (true) {
    for (int k = 0; k < 50; k++) {
      stone[k] = 0;
    }

    int bowl;
    scanf("%d", &n);
    scanf("%d", &p);

    if (n == 0 && p == 0) {
      return 0;
    }

    bowl = p;
    bool flg = true;
    int ans;

    for (int i = 0; flg; i = (++i) % n) {
      if (bowl == 0) {
        bowl = bowl + stone[i];
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