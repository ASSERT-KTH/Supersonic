#include <iostream>
#include <cstdlib>
#include <cstdio>
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
        node(int v) : value(v), priority(rand()), cnt(1), small(v) {
            left = right = NULL;
        }
    };
    
    node* root;
    
    Treap() : root(NULL) {}
    
    int count(node* t) { return !t ? 0 : t->cnt; }
    int mini(node* t) { return !t ? INF : t->small; }
    
    node* update(node* t) {
        t->cnt = count(t->left) + count(t->right) + 1;
        t->small = min(min(mini(t->left), mini(t->right)), t->value);
        return t;
    }
    
    node* merge(node* l, node* r) {
        if (!l || !r)
            return l ? l : r;
        
        node* merged;
        
        while (l && r) {
            if (l->priority > r->priority) {
                l->right = merge(l->right, r);
                merged = l;
                l = l->right;
            } else {
                r->left = merge(l, r->left);
                merged = r;
                r = r->left;
            }
            
            update(merged);
        }
        
        return l ? l : r;
    }
    
    pair<node*, node*> split(node* t, int k) {
        if (!t)
            return make_pair((node*)NULL, (node*)NULL);
        
        node* left = NULL;
        node* right = NULL;
        
        while (t) {
            if (k <= count(t->left)) {
                right = t;
                t = t->left;
                right->left = NULL;
            } else {
                left = t;
                t = t->right;
                left->right = NULL;
                k = k - count(left) - 1;
            }
        }
        
        return make_pair(left, right);
    }
    
    node* insert(node* t, int k, int val) {
        node* newNode = new node(val);
        
        pair<node*, node*> s = split(t, k);
        t = merge(s.first, newNode);
        t = merge(t, s.second);

        return update(t);
    }
    
    node* erase(node* t, int k) {
        pair<node*, node*> s1 = split(t, k + 1);
        pair<node*, node*> s2 = split(s1.first, k);
        
        t = merge(s2.first, s1.second);
        
        return update(t);
    }
    
    node* find(node* t, int k) {
        while (t) {
            int c = count(t->left);
            if (k < c)
                t = t->left;
            else if (k > c)
                t = t->right;
            else
                return t;
        }
        
        return NULL;
    }
    
    int rmq(node* t, int l, int r) {
        if (!t || l >= count(t) || r <= 0)
            return INF;
        
        if (l <= 0 && r >= count(t))
            return mini(t);
        
        int size = count(t->left);
        int ret = min(rmq(t->left, l, r), rmq(t->right, l - size - 1, r - size - 1));
        
        if (l <= size && size < r)
            ret = min(ret, t->value);
        
        return ret;
    }
    
    void insert(int k, int v) { root = insert(root, k, v); }
    void erase(int k) { root = erase(root, k); }
    node* find(int k) { return find(root, k); }
    int rmq(int l, int r) { return rmq(root, l, r); }
};

int main() {
    int n, q;
    Treap tree;
    
    scanf("%d %d", &n, &q);
    
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        tree.insert(i, a);
    }
    
    while (q--) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        
        if (x == 0) {
            z++;
            
            pair<Treap::node*, Treap::node*> a, b, c;
            c = tree.split(tree.root, z);
            b = tree.split(c.first, z - 1);
            a = tree.split(b.first, y);
            
            tree.root = tree.merge(a.first, b.second);
            tree.root = tree.merge(tree.root, a.second);
            tree.root = tree.merge(tree.root, c.second);
        } else if (x == 1) {
            cout << tree.rmq(y, z + 1) << endl;
        } else {
            tree.erase(y);
            tree.insert(y, z);
        }
    }
    
    return 0;
}