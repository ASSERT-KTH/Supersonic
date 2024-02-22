#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  char x[1000005];
  scanf("%s", x);

  int a = 0, b = 0, c = 0, d = 0, maxi = 0;
  for (int i = 0; x[i] != '\0'; i++) {
    switch(x[i]) {
    case 'J':
      a++, b = i + 1;
      break;
    case 'O':
      if (b < i + 1 - a) 
        a++;
      c++, d = i + 1;
      break;
    case 'I':
      if (d < i + 1 - c) 
        c++;
      d = i + 1;
      break;
    default:
      a = b = c = d = i + 1;
    }
    if (a <= b && b <= c && c <= d) {
      maxi = max(maxi, c - b + 1);
    }
  }
  printf("%d\n", maxi);
  return 0;
}