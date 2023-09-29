#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int main() {
    int n, q, C = 0;
    int S[MAX_SIZE], T[MAX_SIZE];
    bool found[MAX_SIZE] = {false};

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &T[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < q; k++) {
            if (S[i] == T[k] && !found[k]) {
                C++;
                found[k] = true;
                break;
            }
        }
    }

    printf("%d\n", C);
    return 0;
}