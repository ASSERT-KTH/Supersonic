#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num_pairs;
    char* pair_values;

    // Loop until scanf fails to read an integer
    while(scanf("%d", &num_pairs) == 1) {
        pair_values = malloc(num_pairs * sizeof(char));
        memset(pair_values, 0, num_pairs * sizeof(char));

        char pair_first, pair_second;
        for(int i = 0; i < num_pairs; i++) {
            scanf(" %c %c", &pair_first, &pair_second);
            pair_values[pair_first] = pair_second;
        }

        int num_tests;
        scanf("%d", &num_tests);

        char test_char;
        for(int i = 0; i < num_tests; i++) {
            scanf(" %c", &test_char);
            putchar(!pair_values[test_char] * test_char + pair_values[test_char]);
        }

        free(pair_values);
        putchar('\n');
    }

    return 0;
}