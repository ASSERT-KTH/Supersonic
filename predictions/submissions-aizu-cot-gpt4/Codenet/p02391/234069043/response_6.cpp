#include <cstdio>
using namespace std;

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  const char *result = (a > b) ? "a > b\n" : (a < b) ? "a < b\n" : "a == b\n";
  printf("%s", result);
  return 0;
}