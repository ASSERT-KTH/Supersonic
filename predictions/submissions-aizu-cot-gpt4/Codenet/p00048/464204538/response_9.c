#include <stdio.h>

typedef struct {
    float upper_limit;
    const char* category;
} WeightCategory;

int main() {
    float f;
    WeightCategory categories[] = {
        { 91, "heavy" },
        { 81, "light heavy" },
        { 75, "middle" },
        { 69, "light middle" },
        { 64, "welter" },
        { 60, "light welter" },
        { 57, "light" },
        { 54, "feather" },
        { 51, "bantam" },
        { 48, "fly" },
        { 0, "light fly" } // 0 is a sentinel value, it will never be reached
    };
    while (scanf("%f", &f) == 1) {
        for (int i = 0; i < sizeof(categories)/sizeof(WeightCategory); ++i) {
            if (f > categories[i].upper_limit) {
                printf("%s\n", categories[i].category);
                break;
            }
        }
    }
    return 0;
}