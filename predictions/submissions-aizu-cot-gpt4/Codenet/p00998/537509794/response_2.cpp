#include <iostream>
#include <algorithm>
#include <climits>

struct RMQ {
    using type = int;
    static type id() { return INT_MAX; }
    static type op(type l, type r) { return std::min(l, r); }
};

// ... rest of the code remains the same ...

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, q;
    std::cin >> n >> q;
    avl_tree<RMQ> tree;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        tree.insert(i, a);
    }
    while (q--) {
        int x, y, z;
        std::cin >> x >> y >> z;
        if (x == 0) {
            int val = tree.find(z);
            tree.erase(z);
            tree.insert(y, val);
        } else if (x == 1) {
            std::cout << tree.find(y, z + 1) << std::endl;
        } else {
            tree.erase(y);
            tree.insert(y, z);
        }
    }
    return 0;
}