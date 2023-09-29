#include <iostream>
#include <utility>
#include <algorithm>
template <class Iterator, class Compare = std::less<>>
void hsort(Iterator a0, Iterator aN, Compare cmp = Compare()) {
    std::make_heap(a0, aN, cmp);
    std::sort_heap(a0, aN, cmp);
}
int main(void) {
    using namespace std;
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    static int a[1000000];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    hsort(a, a + n);
    for (int i = 0; i < n; i++)
        cout << a[i] << ((i == n - 1) ? '\n' : ' ');
    return 0;
}