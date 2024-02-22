#include <stdio.h>

const char* weightClasses[] = {
    "light fly",
    "fly",
    "bantam",
    "feather",
    "light",
    "light welter",
    "welter",
    "light middle",
    "middle",
    "light heavy",
    "heavy"
};

int main() {
    float f;
    int weightClassIndex;
    int count = 0;
    
    while (scanf("%f", &f) == 1) {
        weightClassIndex = (int)f / 3 - 16;
        if (weightClassIndex >= 0 && weightClassIndex < 11) {
            puts(weightClasses[weightClassIndex]);
        } else {
            puts("Invalid weight");
        }
        count++;
    }

    printf("Processed %d input(s)\n", count);
    return 0;
}