#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, S[10000], q, T[500], i, j, cnt = 0;
    bool found[10001] = {false}; //initialize to false
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
        found[S[i]] = true; //mark as found
    }
    scanf("%d", &q);
    for (j = 0; j < q; j++)
        scanf("%d", &T[j]);
    for (i = 0; i < q; i++)
        if (found[T[i]])
            cnt++;
    printf("%d\n", cnt);
    return 0;
}