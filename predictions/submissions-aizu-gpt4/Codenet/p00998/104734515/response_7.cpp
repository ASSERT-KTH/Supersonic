#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

struct Node {
    int value;
    Node *left, *right;
    int priority;
    int cnt;
    int small;
    Node(int v) : value(v), priority(rand()), cnt(1), small(v) {
        left = right = nullptr;
    }
};

class Treap {
    Node *root;

    int count(Node *t) {
        return !t ? 0 : t->cnt;
    }

    int mini(Node *t) {
        return !t ? INF : t->small;
    }

    Node *update(Node *t) {
        t->cnt = count(t->left) + count(t->right) + 1;
        t->small = min({mini(t->left), mini(t->right), t->value});
        return t;
    }

    Node *merge(Node *l, Node *r) {
        if (!l || !r) return l ? l : r;
        if (l->priority > r->priority) {
            l->right = merge(l->right, r);
            return update(l);
        } else {
            r->left = merge(l, r->left);
            return update(r);
        }
    }

    Node *insert(Node *t, int k, int val) {
        Node *new_node = new Node(val);
        auto [left, right] = split(t, k);
        t = merge(merge(left, new_node), right);
        return update(t);
    }

    Node *erase(Node *t, int k) {
        auto [left, right] = split(t, k + 1);
        auto [left2, _] = split(left, k);
        t = merge(left2, right);
        return update(t);
    }

    Node *find(Node *t, int k) {
        int c = count(t->left);
        if (k < c) return find(t->left, k);
        else if (k > c) return find(t->right, k - c - 1);
        else return t;
    }

    int rmq(Node *t, int l, int r) {
        if (l >= count(t) || r <= 0) return INF;
        if (l <= 0 && r >= count(t)) return mini(t);
        int size = count(t->left);
        int ret = min(rmq(t->left, l, r), rmq(t->right, l - size - 1, r - size - 1));
        if (l <= size && size < r) ret = min(ret, t->value);
        return ret;
    }

public:
    Treap() : root(nullptr) {}

    pair<Node *, Node *> split(Node *t, int k) {
        if (!t) return make_pair(nullptr, nullptr);
        if (k <= count(t->left)) {
            auto [left, right] = split(t->left, k);
            t->left = right;
            return {left, update(t)};
        } else {
            auto [left, right] = split(t->right, k - count(t->left) - 1);
            t->right = left;
            return {update(t), right};
        }
    }

    void insert(int k, int v) {
        root = insert(root, k, v);
    }

    void erase(int k) {
        root = erase(root, k);
    }

    Node *find(int k) {
        return find(root, k);
    }

    int rmq(int l, int r) {
        return rmq(root, l, r);
    }

    Node *getRoot() {
        return root;
    }

    void setRoot(Node *newRoot) {
        root = newRoot;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    Treap tree;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        tree.insert(i, a);
    }
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0) {
            z++;
            auto [a1, a2] = tree.split(tree.getRoot(), y);
            auto [b1, b2] = tree.split(a2, z - 1 - y);
            auto [c1, c2] = tree.split(b2, 1);
            tree.setRoot(tree.merge(tree.merge(a1, b1), tree.merge(c1, c2)));
        } else if (x == 1) {
            cout << tree.rmq(y, z + 1) << '\n';
        } else {
            tree.erase(y);
            tree.insert(y, z);
        }
    }
    return 0;
}