#include <cstdio>
using namespace std;

int main() {
    int Q, N, count, tmp, max, S;
    scanf("%d", &Q);
    
    bool table[1000001] = {false};
    for (int loop = 0; loop < Q; loop++) {
        count = 0;
        scanf("%d", &N);
        table[N] = true;
        while (N / 10 != 0) {
            max = 0;
            for (S = 10; N / S != 0; S *= 10) {
                tmp = (N / S) * (N % S);
                max = (max >= tmp) ? max : tmp;
            }
            N = max;
            if (table[N] == true) {
                printf("-1\n");
                break;
            } else {
                table[N] = true;
                count++;
            }
        }
        if (N / 10 == 0) {
            printf("%d\n", count);
        }
        // reset the used elements in table to false for next test case
        for (int i = 0; i <= N; i++) {
            if (table[i]) {
                table[i] = false;
            }
        }
    }
    return 0;
}