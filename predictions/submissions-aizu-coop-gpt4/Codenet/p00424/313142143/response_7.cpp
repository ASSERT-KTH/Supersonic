#include <iostream>
#include <unordered_map>
#include <cstdio>

int main() {
  int n;
  char a, b;
  while ((n = getchar()) != EOF && n != '\n') {
    n -= '0';
    std::unordered_map<char, int> d;
    for (; n--; ) {
      a = getchar(); getchar(); // skip whitespace
      b = getchar(); getchar(); // skip whitespace
      d[a] = b - a;
    }
    n = getchar() - '0';
    for (; n--; ) {
      a = getchar(); getchar(); // skip whitespace
      putchar_unlocked(a + d[a]);
    }
    putchar_unlocked('\n');
  }
  return 0;
}