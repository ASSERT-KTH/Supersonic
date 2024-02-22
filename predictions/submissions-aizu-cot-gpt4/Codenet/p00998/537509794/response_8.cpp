#include <iostream>
#include <climits>
#include <algorithm>

struct RMQ {
    using type = int;
    static constexpr type id() { return INT_MAX; }
    static type op(type l, type r) { return std::min(l, r); }
};

template <typename M> class avl_tree {
    using T = typename M::type;

    struct node {
        T val, all;
        node *ch[2];
        int dep, size;
        node(T v, node *l = nullptr, node *r = nullptr)
            : val(v), all(v), ch{l, r}, dep(1), size(1) {}
    };

    int depth(node *t) const { return t ? t->dep : 0; }
    int count(node *t) const { return t ? t->size : 0; }
    T que(node *t) const { return t ? t->all : M::id(); }
    node *update(node *t) {
        t->dep = std::max(depth(t->ch[0]), depth(t->ch[1])) + 1;
        t->size = count(t->ch[0]) + 1 + count(t->ch[1]);
        t->all = M::op(que(t->ch[0]), M::op(t->val, que(t->ch[1])));
        return t;
    }
    // ... The rest of your code ...

    public:
    avl_tree() : root(nullptr) {}
    int size() const { return count(root); }
    void insert(int k, T b) { root = insert(root, k, b); }
    void erase(int k) { root = erase(root, k); }
    T find(int k) const { return find(root, k)->val; }
    T find(int l, int r) const { return find(root, l, r); }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q;
    std::cin >> n >> q;
    avl_tree<RMQ> tree;
    // ... The rest of your code ...
    return 0;
}