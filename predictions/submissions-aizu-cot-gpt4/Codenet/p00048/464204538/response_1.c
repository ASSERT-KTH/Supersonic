#include <stdio.h>

int main() {
    float f;
    while(scanf("%f", &f) != EOF) {
        if(f <= 48) {
            printf("light fly\n");
            continue;
        }
        if(f <= 51) {
            printf("fly\n");
            continue;
        }
        if(f <= 54) {
            printf("bantam\n");
            continue;
        }
        if(f <= 57) {
            printf("feather\n");
            continue;
        }
        if(f <= 60) {
            printf("light\n");
            continue;
        }
        if(f <= 64) {
            printf("light welter\n");
            continue;
        }
        if(f <= 69) {
            printf("welter\n");
            continue;
        }
        if(f <= 75) {
            printf("light middle\n");
            continue;
        }
        if(f <= 81) {
            printf("middle\n");
            continue;
        }
        if(f <= 91) {
            printf("light heavy\n");
            continue;
        }
        printf("heavy\n");
    }
    return 0;
}