#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE] = {0};
    char *ptr = buffer;

    for (int i = 1; i < 10; i++) {
        ptr += sprintf(ptr, "%dx%d=%d  %dx%d=%d  %dx%d=%d  %dx%d=%d  %dx%d=%d  %dx%d=%d  %dx%d=%d  %dx%d=%d  %dx%d=%d\n", 
            i, 1, i*1,
            i, 2, i*2,
            i, 3, i*3,
            i, 4, i*4,
            i, 5, i*5,
            i, 6, i*6,
            i, 7, i*7,
            i, 8, i*8,
            i, 9, i*9);
    }

    printf("%s", buffer);

    return 0;
}