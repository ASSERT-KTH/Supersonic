#include <stdio.h>
#include <algorithm>

int main() {
    int n, q, C = 0;
    int S[100], T[100];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &S[i]);
    }
    std::sort(S, S+n);

    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d", &T[i]);
        if(std::binary_search(S, S+n, T[i])) {
            ++C;
        }
    }

    printf("%d\n", C);
    return 0;
}