#include <cstdio>
#include <cstring>
using namespace std;
int main() {
  char num[1001];
  while (1) {
    scanf("%s", num);
    if (num[0] == '0')
      break;
    int sum = 0;
    int len = strlen(num);
    for (int i = 0; len > i; i++) {
      sum += num[i] - '0';
    }
    printf("%d\n", sum);
  }
  return 0;
}