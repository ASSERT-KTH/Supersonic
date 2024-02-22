#include <stdio.h>
#include <vector>

int main() {
  int a, b, d = 0;
  std::vector<int> c(999, 0);

  if(scanf("%d", &a)!=1) return 1;
  for (b = a; b--; c[a] = 1)
    if(scanf("%d", &a)!=1) return 1;
    
  if(scanf("%d", &a)!=1) return 1;
  for (b = a; b--; d += c[a])
    if(scanf("%d", &a)!=1) return 1;

  printf("%d\n", d);
  return 0;
}