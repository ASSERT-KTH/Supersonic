#include <iostream>
#include <vector>
#include <random>
using namespace std;

const int INF = 1 << 30;

struct Treap {
    struct node {
        int value;
        node* left;
        node* right;
        int priority;
        int cnt;
        int small;
        node(int v) : value(v), left(nullptr), right(nullptr), priority(0), cnt(1), small(v) {}
    };

    node* root;
    Treap() : root(nullptr) {}

    int count(node* t) {
        return t ? t->cnt : 0;
    }

    int mini(node* t) {
        return t ? t->small : INF;
    }

    node* update(node* t) {
        if (t) {
            t->cnt = count(t->left) + count(t->right) + 1;
            t->small = min(min(mini(t->left), mini(t->right)), t->value);
        }
        return t;
    }

    node* merge(node* l, node* r) {
        if (!l || !r)
            return l ? l : r;

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, count(l) + count(r));

        node* t = nullptr;
        if (dis(gen) < count(l)) {
            l->right = merge(l->right, r);
            t = l;
        }
        else {
            r->left = merge(l, r->left);
            t = r;
        }

        return update(t);
    }

    pair<node*, node*> split(node* t, int k) {
        if (!t)
            return make_pair(nullptr, nullptr);

        node* left = t->left;
        node* right = t->right;

        int size = count(left) + 1;
        if (size <= k) {
            pair<node*, node*> s = split(right, k - size);
            t->right = s.first;
            return make_pair(update(t), s.second);
        }
        else {
            pair<node*, node*> s = split(left, k);
            t->left = s.second;
            return make_pair(s.first, update(t));
        }
    }

    node* insert(node* t, int k, int val) {
        pair<node*, node*> s = split(t, k);
        t = merge(s.first, new node(val));
        return update(merge(t, s.second));
    }

    node* erase(node* t, int k) {
        pair<node*, node*> s1, s2;
        s1 = split(t, k + 1);
        s2 = split(s1.first, k);
        t = merge(s2.first, s1.second);
        return update(t);
    }

    node* find(node* t, int k) {
        while (t) {
            int c = count(t->left);
            if (k < c)
                t = t->left;
            else if (k > c) {
                t = t->right;
                k -= c + 1;
            }
            else
                return t;
        }
        return nullptr;
    }

    int rmq(node* t, int l, int r) {
        if (!t || r <= 0 || l >= count(t))
            return INF;

        int ret = INF;
        int size = count(t->left);
        while (t) {
            if (l <= size && size < r)
                ret = min(ret, t->value);

            if (l < size) {
                t = t->left;
                size -= count(t->right) + 1;
            }
            else if (r > size + 1) {
                t = t->right;
                l -= size + 1;
                size = count(t->left);
            }
            else
                break;
        }
        return ret;
    }

    void insert(int k, int v) {
        root = insert(root, k, v);
    }

    void erase(int k) {
        root = erase(root, k);
    }

    node* find(int k) {
        return find(root, k);
    }

    int rmq(int l, int r) {
        return rmq(root, l, r);
    }
};

int main() {
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
            pair<Treap::node*, Treap::node*> a, b, c;
            c = tree.split(tree.root, z);
            b = tree.split(c.first, z - 1);
            a = tree.split(b.first, y);
            tree.root = tree.merge(a.first, b.second);
            tree.root = tree.merge(tree.root, a.second);
            tree.root = tree.merge(tree.root, c.second);
        }
        else if (x == 1) {
            cout << tree.rmq(y, z + 1) << endl;
        }
        else {
            tree.erase(y);
            tree.insert(y, z);
        }
    }
    return 0;
}