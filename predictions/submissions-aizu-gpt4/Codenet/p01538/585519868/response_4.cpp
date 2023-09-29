#include <cstdio>

int main() {
    int Q, N, count, tmp, max, S;
    bool FLG;
    scanf("%d", &Q);
    for (int loop = 0; loop < Q; loop++) {
        static bool table[1000001] = {0};
        count = 0;
        scanf("%d", &N);
        table[N] = true;
        FLG = false;
        while (N / 10 != 0) {
            max = 0;
            for (S = 10; N / S != 0; S *= 10) {
                tmp = (N / S) * (N % S);
                max = (max >= tmp) ? max : tmp;
            }
            N = max;
            if (table[N]) {
                FLG = true;
                break;
            } else {
                table[N] = true;
                count++;
            }
        }
        printf(FLG ? "-1\n" : "%d\n", count);
        std::fill(table, table + N + 1, false);
    }
    return 0;
}