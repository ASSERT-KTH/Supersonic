#include <cstdio>
using namespace std;
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  const char* results[] = {"a < b\n", "a == b\n", "a > b\n"};
  printf("%s", results[(a > b) + (a == b)]);
  return 0;
}