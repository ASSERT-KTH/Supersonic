#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

template <typename T> void quicksort(T *l, T *r) {
    if (r - l < 2)
        return;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, r - l - 1);
    T *piv = l + dist(mt);
    swap(*l, *piv);
    piv = l;
    r--;
    while (l < r) {
        while (l < r && *l <= *piv)
            l++;
        while (l < r && *r > *piv)
            r--;
        swap(*l, *r);
    }
    T *p = l - 1;
    swap(*p, *piv);
    quicksort(l, p);
    quicksort(p + 1, r);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quicksort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        cout << a[i] << (i == n - 1 ? '\n' : ' ');
}