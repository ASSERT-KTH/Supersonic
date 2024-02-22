#include <iostream>
#include <stdio.h>

int main(void) {
  int S;
  std::cin >> S;
  int remainder = S % 3600;
  printf("%d:%d:%d\n", S / 3600, remainder / 60, remainder % 60);
}