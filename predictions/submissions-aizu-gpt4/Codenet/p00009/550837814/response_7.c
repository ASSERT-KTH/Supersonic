#include <stdio.h>
#include <bitset>

#define MAX_NUM 1000000

int main() {
  std::bitset<MAX_NUM> num;
  num.set();
  num[0] = num[1] = 0;
  for (int i = 2; i * i < MAX_NUM; ++i) {
    if (num[i]) {
      for (int j = i * i; j < MAX_NUM; j += i)
        num[j] = 0;
    }
  }
  for (int i = 1; i < MAX_NUM - 1; ++i) {
    num[i + 1] += num[i];
  }
  int n;
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", num[n] ? 1 : 0);
  }
  return 0;
}