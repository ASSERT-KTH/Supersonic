#include <cstdio>
#include <cstring>

const int MAX_LENGTH = 1000005;

int main() {
  char x[MAX_LENGTH];
  scanf("%s", x);
  
  int length = strlen(x);
  int jCount = 0, oCount = 0, iCount = 0;
  int maxi = 0;
  
  for (int i = 0; i < length; i++) {
    if (x[i] == 'J') {
      jCount++;
    } else if (x[i] == 'O') {
      oCount++;
    } else if (x[i] == 'I') {
      iCount++;
    }
    
    if (jCount >= oCount && oCount <= iCount) {
      maxi = (oCount > maxi) ? oCount : maxi;
    }
  }
  
  printf("%d\n", maxi);
  scanf("%*d");
  return 0;
}