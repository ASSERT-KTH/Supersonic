#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

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
        t->small = min({mini(t->left), mini(t->right), t->value});
        return t;
    }

    node *merge(node *l, node *r) {
        if (!l || !r) return l ? l : r;
        if (l->priority > r->priority) {
            l->right = merge(l->right, r);
        } else {
            r->left = merge(l, r->left);
        }
        return update(l ? l : r);
    }

    pair<node *, node *> split(node *t, int k) {
        if (!t) return make_pair((node *) NULL, (node *) NULL);
        pair<node *, node *> s;
        if (k <= count(t->left)) {
            s = split(t->left, k);
            t->left = s.second;
            s.second = update(t);
        } else {
            s = split(t->right, k - count(t->left) - 1);
            t->right = s.first;
            s.first = update(t);
        }
        return s;
    }

    node *insert(node *t, int k, int val) {
        pair<node *, node *> s = split(t, k);
        return update(merge(merge(s.first, new node(val)), s.second));
    }

    node *erase(node *t, int k) {
        pair<node *, node *> s1 = split(t, k + 1);
        pair<node *, node *> s2 = split(s1.first, k);
        return update(merge(s2.first, s1.second));
    }

    const node *find(node *t, int k) const {
        int c = count(t->left);
        if (k < c) return find(t->left, k);
        if (k > c) return find(t->right, k - c - 1);
        return t;
    }

    int rmq(node *t, int l, int r) {
        if (l >= count(t) || r <= 0) return INF;
        if (l <= 0 && r >= count(t)) return mini(t);
        int size = count(t->left);
        return min({rmq(t->left, l, r), rmq(t->right, l - size - 1, r - size - 1), (l <= size && size < r) ? t->value : INF});
    }

    void insert(int k, int v) { root = insert(root, k, v); }

    void erase(int k) { root = erase(root, k); }

    const node *find(int k) const { return find(root, k); }

    int rmq(int l, int r) { return rmq(root, l, r); }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    Treap tree;
    cin >> n >> q;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        tree.insert(i, a);
    }
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0) {
            z++;
            pair<Treap::node *, Treap::node *> a, b, c;
            c = tree.split(tree.root, z);
            b = tree.split(c.first, z - 1);
            a = tree.split(b.first, y);
            tree.root = tree.merge(a.first, b.second);
            tree.root = tree.merge(tree.root, a.second);
            tree.root = tree.merge(tree.root, c.second);
        } else if (x == 1) {
            cout << tree.rmq(y, z + 1) << '\n';
        } else {
            tree.erase(y);
            tree.insert(y, z);
        }
    }
}