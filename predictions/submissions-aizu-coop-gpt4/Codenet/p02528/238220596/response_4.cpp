#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>

template <class T, class Compare>
void hsort(T& a, std::ptrdiff_t n, Compare cmp) {
    using dif_t = std::ptrdiff_t;
    auto heapify = [&a, &cmp](dif_t p, dif_t hpsz) {
        dif_t c;
        while ((c = (p << 1) + 1) < hpsz) {
            if (c + 1 < hpsz && cmp(a[c], a[c + 1])) {
                ++c;
            }
            if (!cmp(a[p], a[c])) {
                break;
            }
            std::swap(a[p], a[c]);
            p = c;
        }
    };

    // Build the heap
    for (dif_t i = n / 2; i >= 0; --i) {
        heapify(i, n);
    }

    // Swap the root of the heap with the last element and maintain heap property
    for (dif_t i = n - 1; i > 0; --i) {
        std::swap(a[0], a[i]);
        heapify(0, i);
    }
}

template <class Iterator, class Compare>
void hsort(Iterator a0, Iterator aN, Compare cmp) {
    using dif_t = typename std::iterator_traits<Iterator>::difference_type;
    dif_t n = std::distance(a0, aN);
    hsort(*a0, n, cmp);
}

template <class Iterator> void hsort(Iterator a0, Iterator aN) {
    using val_t = typename std::iterator_traits<Iterator>::value_type;
    hsort(a0, aN, std::less<val_t>());
}

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    hsort(a.begin(), a.end());

    for (int i = 0; i < n - 1; i++)
        printf("%d ", a[i]);
    printf("%d\n", a[n - 1]);
    
    return 0;
}