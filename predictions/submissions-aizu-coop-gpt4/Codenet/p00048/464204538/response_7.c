#include <stdio.h>

typedef struct {
    float weight;
    char *class;
} weight_class;

weight_class classes[] = {
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
    {0, "light fly"} // add a sentinel value
};

char* get_weight_class(float weight) {
    int left = 0, right = sizeof(classes) / sizeof(weight_class) - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (classes[mid].weight > weight)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return classes[right].class;
}

int main() {
    float f;
    while (~scanf("%f", &f))
        puts(get_weight_class(f));
    return 0;
}