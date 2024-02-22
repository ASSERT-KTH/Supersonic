#include <stdio.h>

int main(void) {
  int i;
  char str[100];
  for (i = 1; i < 10; i++) {
    sprintf(str, "%dx1=%d\n%dx2=%d\n%dx3=%d\n%dx4=%d\n%dx5=%d\n%dx6=%d\n%dx7=%d\n%dx8=%d\n%dx9=%d\n", 
            i, i*1, i, i*2, i, i*3, i, i*4, i, i*5, i, i*6, i, i*7, i, i*8, i, i*9);
    printf("%s", str);
  }
  return (0);
}