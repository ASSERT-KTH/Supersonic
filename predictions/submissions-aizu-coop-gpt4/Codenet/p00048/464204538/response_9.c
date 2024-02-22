#include <stdio.h>

typedef struct {
    float weight;
    char* category;
} WeightCategory;

int main() {
    WeightCategory categories[] = {
        {91, "heavy"},
        {81, "light heavy"},
        {75, "middle"},
        {69, "light middle"},
        {64, "welter"},
        {60, "light welter"},
        {57, "light"},
        {54, "feather"},
        {51, "bantam"},
        {48, "fly"},
        {0,  "light fly"}
    };

    float f;
    while (~scanf("%f", &f)) {
        int i;
        for (i = 0; i < sizeof(categories)/sizeof(WeightCategory); i++) {
            if (f > categories[i].weight) {
                puts(categories[i].category);
                break;
            }
        }
    }

    return 0;
}