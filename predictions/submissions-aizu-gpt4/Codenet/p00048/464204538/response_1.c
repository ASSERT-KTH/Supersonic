#include <stdio.h>

int main() {
    float f;
    while (scanf("%f", &f) != EOF) {
        const char* weight_class;
        if (f > 91) weight_class = "heavy";
        else if (f > 81) weight_class = "light heavy";
        else if (f > 75) weight_class = "middle";
        else if (f > 69) weight_class = "light middle";
        else if (f > 64) weight_class = "welter";
        else if (f > 60) weight_class = "light welter";
        else if (f > 57) weight_class = "light";
        else if (f > 54) weight_class = "feather";
        else if (f > 51) weight_class = "bantam";
        else if (f > 48) weight_class = "fly";
        else weight_class = "light fly";
        puts(weight_class);
    }
    return 0;
}