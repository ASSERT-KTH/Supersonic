#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using dif_t = std::ptrdiff_t;
template <class T, class Compare>
void heapify(T a, dif_t p, dif_t hpsz, Compare cmp) {
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
}

template <class Iterator>
void hsort(Iterator a0, Iterator aN) {
    using val_t = typename std::iterator_traits<Iterator>::value_type;
    using dif_t = typename std::iterator_traits<Iterator>::difference_type;
    dif_t n = std::distance(a0, aN);
    if (n < 2) {
        return;
    }
    for (dif_t i = n / 2; i >= 0; --i) {
        heapify(a0, i, n, std::less<val_t>());
    }
    for (dif_t i = n - 1; i > 0; --i) {
        std::swap(a0[0], a0[i]);
        heapify(a0, 0, i, std::less<val_t>());
    }
}

int main() {
    using namespace std;
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    hsort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        cout << a[i] << ((i == n - 1) ? '\n' : ' ');
    return 0;
}