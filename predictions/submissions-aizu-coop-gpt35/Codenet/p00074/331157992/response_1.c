#include <stdio.h>

#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60

int main() {
    int h, m, s, t;

    // Get input time
    while (scanf("%d%d%d", &h, &m, &s) && (h != 0 || m != 0 || s != 0)) {
        // Calculate time after 2 hours and 3 hours
        t = (120 - h * 60 - m) * 60 - s;

        // Print the calculated times
        printf("%02d:%02d:%02d\n", (t + 2 * SECONDS_IN_HOUR) / SECONDS_IN_HOUR,
                                   (t + 2 * SECONDS_IN_HOUR) / SECONDS_IN_MINUTE % SECONDS_IN_MINUTE,
                                   (t + 2 * SECONDS_IN_HOUR) % SECONDS_IN_MINUTE);

        printf("%02d:%02d:%02d\n", (t + 3 * SECONDS_IN_HOUR) / SECONDS_IN_HOUR,
                                   (t + 3 * SECONDS_IN_HOUR) / SECONDS_IN_MINUTE % SECONDS_IN_MINUTE,
                                   (t + 3 * SECONDS_IN_HOUR) % SECONDS_IN_MINUTE);
    }

    return 0;
}