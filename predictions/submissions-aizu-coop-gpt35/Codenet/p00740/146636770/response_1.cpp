#include <iostream>

int main() {
  int stone[50] = {0}; // Initialize the stone array outside the while loop
  int n, p;

  while (true) {
    std::cin >> n >> p;

    if (n == 0 && p == 0) {
      return 0;
    }

    int bowl = p;
    bool flg = true;
    int ans = 0;

    for (int i = 0; flg; i = (i + 1) % n) {
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

    // Print the result
    std::cout << ans << std::endl;
  }
}