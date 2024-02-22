#include <cstdio>

int main() {
  int n;
  scanf("%d", &n); // using scanf instead of cin
  int square = n * n; // calculate n * n once
  printf("%d\n", square * n); // using printf instead of cout and calculating cube by multiplying square with n
  return 0;
}