#include <cstdio>
#include <cstring>
#include <cmath>

const int MAX = 1000000;
int num[MAX];

int main() {
  std::memset(num, 1, sizeof(num));
  num[0] = num[1] = 0;
  int limit = std::sqrt(MAX);
  for (int i = 2; i <= limit; ++i) {
    if (num[i]) {
      for (int j = i * i; j < MAX; j += i)
        num[j] = 0;
    }
  }
  for (int i = 1; i < MAX; ++i) {
    num[i] += num[i - 1];
  }
  int n;
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", num[n]);
  }
  return 0;
}