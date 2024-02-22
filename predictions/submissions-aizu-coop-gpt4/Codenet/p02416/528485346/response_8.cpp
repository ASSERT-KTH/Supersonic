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
    int numLength = strlen(num);  // Calculate string length once before the loop
    for (int i = 0; i < numLength; i++) {  // Use pre-calculated string length
      sum += num[i] - '0';
    }
    printf("%d\n", sum);
  }
  return 0;
}