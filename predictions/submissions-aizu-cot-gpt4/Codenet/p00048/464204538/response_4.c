#include <stdio.h>

int main() {
    float f;
    const char* categories[] = {"light fly", "fly", "bantam", "feather", "light", "light welter", "welter", 
                                "light middle", "middle", "light heavy", "heavy"};
    int weights[] = {48, 51, 54, 57, 60, 64, 69, 75, 81, 91};

    while(scanf("%f", &f) != EOF) {
        int i;
        for (i = 0; i < 10; i++) {
            if (f <= weights[i]) {
                break;
            }
        }
        puts(categories[i]);
    }
    return 0;
}