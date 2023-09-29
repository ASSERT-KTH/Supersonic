#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  char num[1001];
  while (scanf("%s", num) == 1) {
    if (num[0] == '0')
      break;
    int sum = 0;
    for (int i = 0, len = strlen(num); i < len; i++) {
      sum += num[i] - '0';
    }
    printf("%d\n", sum);
  }
  return 0;
}