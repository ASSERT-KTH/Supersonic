#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

template <class Key>
struct RandomizedBinarySearchTree {
    struct Node {
        Node* l;
        Node* r;
        int cnt;
        Key key;
        Node() {}
        Node(const Key& k) : cnt(1), key(k), l(nullptr), r(nullptr) {}
    };

    vector<Node*> pool;
    int ptr;

    RandomizedBinarySearchTree(int sz) : pool(sz), ptr(0) {}

    inline Node* alloc(const Key& key) { return new Node(key); }

    virtual Node* clone(Node* t) { return alloc(t->key); }

    inline int count(const Node* t) { return t ? t->cnt : 0; }

    inline Node* update(Node* t) {
        t->cnt = count(t->l) + count(t->r) + 1;
        return t;
    }

    Node* propagete(Node* t) { return update(clone(t)); }

    Node* merge(Node* l, Node* r) {