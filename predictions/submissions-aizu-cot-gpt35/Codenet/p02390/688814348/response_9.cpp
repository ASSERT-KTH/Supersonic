#include <iostream>
#include <cstdio>

int main(void) {
  int S;
  std::cin >> S;
  printf("%d:%d:%d\n", S / 3600, (S % 3600) / 60, (S % 60));
}