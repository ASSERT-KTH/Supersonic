#include <cstdio>
using namespace std;
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  const char* outputs[] = {"a > b\n", "a < b\n", "a == b\n"};
  printf(outputs[(a > b) ? 0 : (a < b) ? 1 : 2]);
  return 0;
}