#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

int a[1000010];

template <typename T>
void quicksort(T* l, T* r) {
    T* begin = l;
    struct range {
        T* l, * r;
    };
    static range s[300];
    auto partition = [&](T* l, T* r) {
        if (r - l < 2)
            return (T*)nullptr;
        T* piv = r - 1;  // Use last element as pivot
        T i = l - 1;

        // Partition operation optimized to reduce unnecessary swaps
        for (T* j = l; j <= r - 1; j++) {
            if (*j < *piv) {
                i++;
                swap(*i, *j);
            }
        }
        swap(*(i + 1), *piv);
        return i + 1;
    };
    int sz = 0;
    s[sz++] = { l, r };
    while (sz) {
        T* l = s[--sz].l;
        T* r = s[sz].r;
        T* p = partition(l, r);
        if (p != nullptr) {
            if (p + 1 < r)
                s[sz++] = { p + 1, r };
            if (l < p)
                s[sz++] = { l, p };
        }
    }
}

int main() {
    srand(time(0));
    int n;
    std::ios::sync_with_stdio(false);  // Faster I/O
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quicksort(a, a + n);
    for (int i = 0; i < n; i++)
        cout << a[i] << (i == n - 1 ? '\n' : ' ');
}