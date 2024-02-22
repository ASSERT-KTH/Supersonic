#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main() {
  string x;
  char temp[1000005];
  scanf("%s", temp);
  x = temp;
  int leng = x.length();
  int count = 0;
  int maxi = -1;
  
  for (int a = 0; a < leng; a++) {
    char currentChar = x[a];
    
    if (currentChar == 'J') {
      count++;
      
      if (count == 1) {
        int b = count;
      } else if (count == 2) {
        int c = count;
      } else if (count == 3) {
        int d = count;
        if (b >= c && c <= d) {
          maxi = max(maxi, c);
        }
      }
    } else {
      count = 0;
    }
  }
  
  printf("%d\n", maxi);
  scanf("%d", &count);
  return 0;
}