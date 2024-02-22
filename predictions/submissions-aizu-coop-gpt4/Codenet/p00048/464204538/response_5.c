#include <stdio.h>

typedef struct {
    float weight;
    const char* label;
} WeightCategory;

static const WeightCategory weightCategories[] = {
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
    {0, "light fly"}
};

int main() {
    float f;
    while(scanf("%f", &f) != EOF) {
        for(int i = 0; i < sizeof(weightCategories) / sizeof(WeightCategory); i++) {
            if(f > weightCategories[i].weight) {
                printf("%s\n", weightCategories[i].label);
                break;
            }
        }
    }
    return 0;
}