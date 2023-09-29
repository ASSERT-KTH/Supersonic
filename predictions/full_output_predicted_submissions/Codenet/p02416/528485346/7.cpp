#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  char s[1001];
  while (1) {
    scanf("%s", s);
    if (s[0] == '0')
      break;
    int sum = 0;
    for (int i = 0; strlen(s) > i; i++) {
      sum += s[i] - '0';
    }
    printf("%d\n", sum);
  }
  return 0;
}
