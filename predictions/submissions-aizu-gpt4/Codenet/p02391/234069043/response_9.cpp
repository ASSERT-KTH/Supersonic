#include <cstdio>
using namespace std;
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if (a == b)
    puts("a == b");
  else
    printf("a %c b\n", a > b ? '>' : '<');
  return 0;
}