#include <cstdio>
#include <algorithm>

void hsort(int* a, int n) {
    if (n < 2) {
        return;
    }

    auto heapify = [](int* a, int p, int hpsz) {
        int c;
        while ((c = (p << 1) + 1) < hpsz) {
            if (c + 1 < hpsz && a[c] < a[c + 1]) {
                ++c;
            }
            if (!(a[p] < a[c])) {
                break;
            }
            std::swap(a[p], a[c]);
            p = c;
        }
    };

    for (int i = n / 2; i >= 0; --i) {
        heapify(a, i, n);
    }
    for (int i = n - 1; i > 0; --i) {
        std::swap(a[0], a[i]);
        heapify(a, 0, i);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    hsort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d%c", a[i], (i == n - 1) ? '\n' : ' ');
    }
    delete[] a;
    return 0;
}