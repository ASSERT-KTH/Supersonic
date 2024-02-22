#include <stdio.h>

#define NUM_CLASSES 11

const float weight_limits[NUM_CLASSES] = {75, 69, 64, 60, 57, 54, 51, 48, 81, 91};
const char* class_names[NUM_CLASSES] = {"middle", "light middle", "welter", "light welter", "light", "feather", "bantam", "fly", "light heavy", "heavy", "light fly"};

int main() {
    float f;
    while (scanf("%f", &f) == 1) {
        int i;
        for (i = 0; i < NUM_CLASSES - 1; i++) {
            if (f > weight_limits[i]) {
                puts(class_names[i]);
                break;
            }
        }
        if (i == NUM_CLASSES - 1) {
            puts(class_names[i]);
        }
    }
    return 0;
}