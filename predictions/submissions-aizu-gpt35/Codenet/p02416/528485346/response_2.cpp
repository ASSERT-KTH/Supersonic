#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1005;
int main() {
  char num[MAXN];
  while (scanf("%s", num) != EOF && num[0] != '0') {
    int sum = 0;
    for (int i = 0; num[i]; i++) {
      sum += num[i] - '0';
    }
    printf("%d\n", sum);
  }
  return 0;
}