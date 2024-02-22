#include <iostream>
#include <map>

int main() {
  int n;
  while (scanf("%d", &n) == 1 && n) {
    std::map<char, int> d;
    char a, b;
    while (n--) {
      scanf(" %c %c", &a, &b);
      d[a] = b - a;
    }
    while (scanf(" %c", &a) == 1) {
      putchar(a + d[a]);
    }
    putchar('\n');
  }
  return 0;
}