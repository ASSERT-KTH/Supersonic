#include <stdio.h>
#include <vector>
#include <algorithm>

int main(void) {
  int n;
  scanf("%d", &n);
  std::vector<int> S(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);
  std::sort(S.begin(), S.end());
  for (int i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n%d\n", n);
  return 0;
}