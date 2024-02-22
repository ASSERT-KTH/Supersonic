#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  int num, cap, price;
  while (scanf("%d%d", &num, &cap) != EOF) {
    if (num == 0 && cap == 0) {
      break;
    }
    int vegetables[num];
    for (int i = 0; i < num; ++i) {
      scanf("%d", &price);
      vegetables[i] = price;
    }
    std::sort(vegetables, vegetables+num, std::greater<int>());
    int sum = 0;
    for (int i = 0; i < num; ++i) {
      if ((i + 1) % cap != 0) {
        sum += vegetables[i];
      }
    }
    printf("%d\n", sum);
  }
  return 0;
}