#include <stdio.h>

int main() {
    float f;
    const char* result;
    while(scanf("%f", &f) != EOF) {
        if (f > 91)
            result = "heavy";
        else if (f > 81)
            result = "light heavy";
        else if (f > 75)
            result = "middle";
        else if (f > 69)
            result = "light middle";
        else if (f > 64)
            result = "welter";
        else if (f > 60)
            result = "light welter";
        else if (f > 57)
            result = "light";
        else if (f > 54)
            result = "feather";
        else if (f > 51)
            result = "bantam";
        else if (f > 48)
            result = "fly";
        else
            result = "light fly";
        
        puts(result);
    }
    return 0;
}