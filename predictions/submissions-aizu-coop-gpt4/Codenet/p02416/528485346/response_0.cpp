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
    int sum = 0;
    int length = strlen(num);  // Store the string length before the loop starts
    for (int i = 0; i < length; i++) {  // Use the pre-computed string length
      sum += num[i] - '0';
    }
    printf("%d\n", sum);
  }
  return 0;
}