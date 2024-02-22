#include <stdio.h>

int main(void) {
    int i;
    char line[50];
    for (i = 1; i < 10; i++) {
        sprintf(line, "%dx1=%d %dx2=%d %dx3=%d %dx4=%d %dx5=%d %dx6=%d %dx7=%d %dx8=%d %dx9=%d\n", 
                i, i*1, i, i*2, i, i*3, i, i*4, i, i*5, i, i*6, i, i*7, i, i*8, i, i*9);
        printf("%s", line);
    }
    return 0;
}