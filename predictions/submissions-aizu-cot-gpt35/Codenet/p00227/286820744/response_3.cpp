#include <iostream>
#include <algorithm>

int main() {
  int num, cap;
  while (std::scanf("%d %d", &num, &cap) == 2) {
    if (num == 0 && cap == 0) {
      break;
    }
    int vegetables[num];
    for (int i = 0; i < num; ++i) {
      std::scanf("%d", &vegetables[i]);
    }
    int sum = 0;
    for (int i = 0; i < num; ++i) {
      int maxIndex = 0;
      for (int j = 1; j < num - i; ++j) {
        if (vegetables[j] > vegetables[maxIndex]) {
          maxIndex = j;
        }
      }
      if ((i + 1) % cap != 0) {
        sum += vegetables[maxIndex];
      }
      std::swap(vegetables[maxIndex], vegetables[num - i - 1]);
    }
    std::cout << sum << std::endl;
  }
}