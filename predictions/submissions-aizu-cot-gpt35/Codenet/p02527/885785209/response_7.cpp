#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <algorithm>

const int MAX_SIZE = 1000010;

template <typename T>
void partition(T* l, T* r) {
    if (r - l < 2)
        return;
    T* piv = l + rand() % (r - l);
    if (*piv == *std::max_element(l, r)) {
        std::swap(*piv, *(r - 1));
        return;
    }
    std::swap(*l, *piv);
    piv = l;
    r--;
    while (l < r) {
        while (l < r && *l <= *piv)
            l++;
        while (l < r && *r > *piv)
            r--;
        std::swap(*l, *r);
    }
    T* p = l - 1;
    std::swap(*p, *piv);
}

template <typename T>
void quicksort(T* l, T* r) {
    struct Range {
        T* l;
        T* r;
    };
    std::stack<Range> s;
    s.push({ l, r });

    while (!s.empty()) {
        T* l = s.top().l;
        T* r = s.top().r;
        s.pop();
        T* p = partition(l, r);
        if (p != nullptr) {
            if (p + 1 < r)
                s.push({ p + 1, r });
            if (l < p)
                s.push({ l, p });
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    int a[MAX_SIZE];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    quicksort(a, a + n);

    for (int i = 0; i < n; i++)
        std::cout << a[i] << (i == n - 1 ? '\n' : ' ');

    return 0;
}