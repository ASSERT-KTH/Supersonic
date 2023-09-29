#include <cstdio>
using namespace std;

int main() {
  int a, b;
  scanf("%d %d", &a, &b);

  const char* comparison = a > b ? "a > b" : a < b ? "a < b" : "a == b";
  printf("%s\n", comparison);

  return 0;
}