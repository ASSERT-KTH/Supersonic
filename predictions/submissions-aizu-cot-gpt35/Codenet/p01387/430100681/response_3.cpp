#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>
using namespace std;

template <class Key>
struct RandomizedBinarySearchTree {
    struct Node {
        Node *l, *r;
        int cnt;
        Key key;
        Node() {}
        Node(const Key &k) : cnt(1), key(k), l(nullptr), r(nullptr) {}
    };

    vector<Node*> pool;
    int ptr;
    mt19937 rng; // Faster random number generator

    RandomizedBinarySearchTree() : ptr(0), rng(random_device{}()) {}

    Node* alloc(const Key &key) {
        return &(pool[ptr++] = Node(key));
    }

    int count(const Node *t) {
        return t ? t->cnt : 0;
    }

    Node* update(Node *t) {
        t->cnt = count(t->l) + count(t->r) + 1;
        return t;
    }

    Node* merge(Node *l, Node *r) {
        if (!l || !r)
            return l ? l : r;
        uniform_int_distribution<int> uni(0, l->cnt + r->cnt - 1);
        if (uni(rng) < l->cnt) {
            l->r = merge(l->r, r);
            return update(l);
        } else {
            r->l = merge(l, r->l);
            return update(r);
        }
    }

    pair<Node*, Node*> split(Node *t, int k) {
        if (!t)
            return {t, t};
        if (k <= count(t->l)) {
            auto s = split(t->l, k);
            t->l = s.second;
            return {s.first, update(t)};
        } else {
            auto s = split(t->r, k - count(t->l) - 1);
            t->r = s.first;
            return {update(t), s.second};
        }
    }

    Node* build(int l, int r, const vector<Key> &v) {
        if (l + 1 >= r)
            return alloc(v[l]);
        return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
    }

    Node* build(const vector<Key> &v) {
        ptr = 0;
        return build(0, (int)v.size(), v);
    }

    void dump(Node *r, vector<Key> &v, int &idx) {
        if (!r)
            return;
        dump(r->l, v, idx);
        v[idx++] = r->key;
        dump(r->r, v, idx);
    }

    vector<Key> dump(Node *r) {
        vector<Key> v((size_t)count(r));
        int idx = 0;
        dump(r, v, idx);
        return v;
    }

    void insert(Node *&t, int k, const Key &v) {