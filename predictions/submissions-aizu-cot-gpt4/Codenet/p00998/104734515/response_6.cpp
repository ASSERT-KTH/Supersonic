#include <iostream>
#include <cstdlib>

const int INF = 1 << 30;

struct Treap {
    struct node {
        int value;
        node *left, *right;
        int priority;
        int cnt;
        int small;
        node(int v) : value(v), priority(rand()), cnt(1), small(v) {
            left = right = NULL;
        }
    };

    node *root;

    Treap() : root(NULL) {}

    int count(node *t) { return !t ? 0 : t->cnt; }

    int mini(node *t) { return !t ? INF : t->small; }

    node *update(node *t) {
        t->cnt = count(t->left) + count(t->right) + 1;
        t->small = std::min(std::min(mini(t->left), mini(t->right)), t->value);
        return t;
    }

    node *merge(node *l, node *r) {
        if (!l || !r)
            return l ? l : r;
        if (l->priority > r->priority) {
            l->right = merge(l->right, r);
            return update(l);
        } else {
            r->left = merge(l, r->left);
            return update(r);
        }
    }

    std::pair<node *, node *> split(node *t, int k) {
        if (!t)
            return std::make_pair((node *)NULL, (node *)NULL);
        if (k <= count(t->left)) {
            std::pair<node *, node *> s = split(t->left, k);
            t->left = s.second;
            return std::make_pair(s.first, update(t));
        } else {
            std::pair<node *, node *> s = split(t->right, k - count(t->left) - 1);
            t->right = s.first;
            return std::make_pair(update(t), s.second);
        }
    }

    node *insert(node *t, int k, int val) {
        std::pair<node *, node *> s = split(t, k);
        t = merge(s.first, new node(val));
        return merge(t, s.second);
    }

    node *erase(node *t, int k) {
        std::pair<node *, node *> s1, s2;
        s1 = split(t, k + 1);
        s2 = split(s1.first, k);
        return merge(s2.first, s1.second);
    }

    node *find(node *t, int k) {
        int c = count(t->left);
        if (k < c)
            return find(t->left, k);
        else if (k > c)
            return find(t->right, k - c - 1);
        else
            return t;
    }

    int rmq(node *t, int l, int r) {
        if (l >= count(t) || r <= 0)
            return INF;
        if (l <= 0 && r >= count(t))
            return mini(t);
        int size = count(t->left);
        int ret = std::min(rmq(t->left, l, r), rmq(t->right, l - size - 1, r - size - 1));
        if (l <= size && size < r)
            ret = std::min(ret, t->value);
        return ret;
    }

    void insert(int k, int v) { root = insert(root, k, v); }

    void erase(int k) { root = erase(root, k); }

    node *find(int k) { return find(root, k); }

    int rmq(int l, int r) { return rmq(root, l, r); }
};

int main() {
    int n, q;
    Treap tree;
    std::cin >> n >> q;
    for (int i = 0, a; i < n; i++) {
        std::cin >> a;
        tree.insert(i, a);
    }
    while (q--) {
        int x, y, z;
        std::cin >> x >> y >> z;
        if (x == 0) {
            z++;
            tree.root = tree.merge(tree.merge(tree.split(tree.split(tree.split(tree.root, z).first, z - 1).first, y).first, tree.split(tree.split(tree.root, z).first, z - 1).second), tree.split(tree.split(tree.root, z).first, y).second);
            tree.root = tree.merge(tree.root, tree.split(tree.root, z).second);
        } else if (x == 1) {
            std::cout << tree.rmq(y, z + 1) << std::endl;
        } else {
            tree.erase(y);
            tree.insert(y, z);
        }
    }
}