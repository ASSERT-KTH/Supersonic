#include <stdio.h>

const char* weight_categories[] = {
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
    while (scanf("%f", &f) == 1) {
        int index = (int)f - 48;
        if (index >= 0 && index < 11) {
            puts(weight_categories[index]);
        } else {
            puts("Invalid weight");
        }
    }
    return 0;
}