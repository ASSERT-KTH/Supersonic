#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  char num[1001];
  while (1) {
    scanf("%s", num);
    if (num[0] == '0')
      break;
    int sum = strlen(num);
    printf("%d\n", sum);
  }
  return 0;
}
