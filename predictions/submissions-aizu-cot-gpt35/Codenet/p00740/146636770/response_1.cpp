#include <iostream>
int main(void) {
  while (1) {
    int n, p;
    std::cin >> n;
    std::cin >> p;
    if (n == 0 && p == 0) {
      return 0;
    }
    int* stone = new int[n];
    int bowl = p;
    int ans = -1;
    for (int i = 0; ans == -1; i = (i + 1) % n) {
      if (bowl == 0) {
        bowl = bowl + stone[i];
        stone[i] = 0;
      } else {
        stone[i]++;
        bowl--;
        if (bowl == 0 && stone[i] == p) {
          ans = i;
        }
      }
    }
    delete[] stone;
    std::cout << ans << std::endl;
  }
}