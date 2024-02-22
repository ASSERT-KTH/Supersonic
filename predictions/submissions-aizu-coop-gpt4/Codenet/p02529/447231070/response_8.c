#include <stdio.h>
#include <unordered_map>

int main() {
  int a, b, d = 0;
  std::unordered_map<int, int> counts;

  scanf("%d", &a);
  for (int i = 0; i < a; i++) {
    scanf("%d", &b);
    counts[b] = 1;
  }

  scanf("%d", &a);
  for (int i = 0; i < a; i++) {
    scanf("%d", &b);
    d += counts[b];
  }

  printf("%d\n", d);
  return 0;
}