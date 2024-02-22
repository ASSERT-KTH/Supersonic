#include <stdio.h>

int main() {
    int count[5004], diff[5004], max_diff = 0, temp = 0, max_temp = 0, index = 0;
    char format[] = "%d\n";

    for (scanf("%d%*d", count); index < *count; scanf(format, ++index + count))
        ;

    int num;
    for (; ~scanf(format, &num);)
        for (max_temp = index = temp = 0; index++ < *count; temp = diff[index], diff[index] = max_diff < max_temp ? max_diff = max_temp : max_temp)
            max_temp = num - count[index] ? max_temp : temp + 1;

    printf(format, max_diff);

    return 0;
}