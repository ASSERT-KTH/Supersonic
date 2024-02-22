#include <stdio.h>

// Define a structure to hold the weight limit and the corresponding weight class name
struct weight_class {
    float limit;
    char *name;
};

// Define an array of weight classes
struct weight_class classes[] = {
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
    {0, "light fly"},
};

int main() {
    float f;

    while (~scanf("%f", &f)) {
        for (int i = 0; i < sizeof(classes)/sizeof(classes[0]); ++i) {
            if (f > classes[i].limit) {
                puts(classes[i].name);
                break;
            }
        }
    }

    return 0;
}