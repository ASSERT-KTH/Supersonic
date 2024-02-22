#include <stdio.h>

typedef enum {
    HEAVY,
    LIGHT_HEAVY,
    MIDDLE,
    LIGHT_MIDDLE,
    WELTER,
    LIGHT_WELTER,
    LIGHT,
    FEATHER,
    BANTAM,
    FLY,
    LIGHT_FLY
} WeightClass;

const char* weightClassNames[] = {
    "heavy",
    "light heavy",
    "middle",
    "light middle",
    "welter",
    "light welter",
    "light",
    "feather",
    "bantam",
    "fly",
    "light fly"
};

int main() {
    float f;
    while (scanf("%f", &f) == 1) {
        WeightClass weightClass;

        if (f > 91)
            weightClass = HEAVY;
        else if (f > 81)
            weightClass = LIGHT_HEAVY;
        else if (f > 75)
            weightClass = MIDDLE;
        else if (f > 69)
            weightClass = LIGHT_MIDDLE;
        else if (f > 64)
            weightClass = WELTER;
        else if (f > 60)
            weightClass = LIGHT_WELTER;
        else if (f > 57)
            weightClass = LIGHT;
        else if (f > 54)
            weightClass = FEATHER;
        else if (f > 51)
            weightClass = BANTAM;
        else if (f > 48)
            weightClass = FLY;
        else
            weightClass = LIGHT_FLY;

        printf("%s\n", weightClassNames[weightClass]);
    }
    
    return 0;
}