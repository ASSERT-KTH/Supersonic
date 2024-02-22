#include <cstdio>

int main() {
  int n, m;
  if(scanf("%d%d", &n, &m) != 2) { // To handle scanf error
     fprintf(stderr, "Failed to read n and m\n");
     return 1;
  }
  printf("%d\n", n - m - 1);
  return 0;
}