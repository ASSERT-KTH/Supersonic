#include <bits/stdc++.h>
using namespace std;

struct RMQ {
    using type = int;
    static type id() { return INT_MAX; }
    static type op(type l, type r) { return min(l, r); }
};

template <typename M> class avl_tree {
    using T = typename M::type;
    struct Node {
        T val, all;
        Node *ch[2];
        int dep, size;
        Node(T v, Node *l = nullptr, Node *r = nullptr)
            : val(v), all(v), ch{l, r}, dep(1), size(1) {}
    };

    int depth(Node *t) const { return t ? t->dep : 0; }
    int count(Node *t) const { return t ? t->size : 0; }
    T que(Node *t) const { return t ? t->all : M::id(); }
    Node* update(Node *t) {
        t->dep = max(depth(t->ch[0]), depth(t->ch[1])) + 1;
        t->size = count(t->ch[0]) + 1 + count(t->ch[1]);
        t->all = M::op(M::op(que(t->ch[0]), t->val), que(t->ch[1]));
        return t;
    }
    Node* rotate(Node *t, int b) {
        Node *s = t->ch[1 - b];
        t->ch[1 - b] = s->ch[b];
        s->ch[b] = t;
        update(t);
        return update(s);
    }
    Node* balance(Node *t) {
        for (int b = 0; b < 2; ++b) {
            if (depth(t->ch[b]) - depth(t->ch[!b]) < -1) {
                if (depth(t->ch[b]->ch[!b]) - depth(t->ch[b]->ch[b]) > 0)
                    t->ch[b] = rotate(t->ch[b], b);
                return rotate(t, !b);
            }
        }
        return update(t);
    }
    Node* insert(Node *t, int k, const T &v) {
        if (!t) return new Node(v);
        int c = count(t->ch[0]);
        if (k <= c)
            t->ch[0] = insert(t->ch[0], k, v);
        else
            t->ch[1] = insert(t->ch[1], k - c - 1, v);
        return balance(t);
    }
    Node* erase(Node *t, int k) {
        if (!t) return nullptr;
        int c = count(t->ch[0]);
        if (k == c) {
            if (!t->ch[0] || !t->ch[1]) {
                Node *to_delete = t;
                t = t->ch[!t->ch[0]];
                delete to_delete;
            } else {
                t->val = find(t->ch[1], 0)->val;
                t->ch[1] = erase(t->ch[1], 0);
            }
        } else {
            t->ch[k < c] = erase(t->ch[k < c], k < c ? k : k - c - 1);
        }
        return balance(t);
    }
    Node* find(Node *t, int k) const {
        if (!t) return nullptr;
        int c = count(t->ch[0]);
        if (k == c) return t;
        return find(t->ch[k < c], k < c ? k : k - c - 1);
    }
    T find(Node *t, int l, int r) const {
        if (!t || r <= 0 || l >= count(t)) return M::id();
        T res = M::id();
        int c = count(t->ch[0]);
        if (l <= c && c < r) res = M::op(res, t->val);
        if (l < c) res = M::op(res, find(t->ch[0], l, min(r, c)));
        if (r > c + 1) res = M::op(res, find(t->ch[1], max(0, l - c - 1), r - c - 1));
        return res;
    }
    Node *root;
public:
    avl_tree() : root(nullptr) {}
    int size() const { return count(root); }
    void insert(int k, T b) { root = insert(root, k, b); }
    void erase(int k) { root = erase(root, k); }
    T find(int k) const { return find(root, k)->val; }
    T find(int l, int r) const { return find(root, l, r); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    avl_tree<RMQ> tree;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        tree.insert(i, a);
    }
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0) {
            int val = tree.find(z);
            tree.erase(z);
            tree.insert(y, val);
        } else if (x == 1) {
            cout << tree.find(y, z + 1) << "\n";
        } else {
            tree.erase(y);
            tree.insert(y, z);
        }
    }
    return 0;
}