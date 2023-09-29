#include <algorithm>
#include <cstdio>

constexpr size_t kMaxArraySize = 1000001;

int main() {
    int n;
    static int A[kMaxArraySize];  // static to move large array out of stack

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", A + i);
    }

    std::sort(A, A + n);

    if (n > 0) {
        printf("%d", A[0]);

        for (int i = 1; i < n; ++i) {
            printf(" %d", A[i]);
        }
    }

    puts("");
}