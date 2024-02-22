#include <cstdio>
#include <cstdint>
using namespace std;
int main() {
  uint64_t a = 1;
  int i, n;
  scanf("%d", &n);
  for (i = n; i > 1; i -= 2) {
    if (i == 2 || i == 3) 
        a *= i;
    else
        a *= i * (i - 2);
  }
  printf("%llu\n", a);
  return 0;
}