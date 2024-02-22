#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct Node {
    Node* l;
    Node* r;
    int cnt;
    int key;
    Node() : l(nullptr), r(nullptr), cnt(0), key(0) {}
};

class RandomizedBinarySearchTree {
private:
    vector<Node> pool;
    int ptr;
    Node* free_list;

public:
    RandomizedBinarySearchTree(int sz) : pool(sz), ptr(0), free_list(nullptr) {}

    Node* allocate(int key) {
        if (free_list) {
            Node* node = free_list;
            free_list = free_list->r;
            node->l = nullptr;
            node->r = nullptr;
            node->cnt = 1;
            node->key = key;
            return node;
        }
        return &(pool[ptr++] = Node{nullptr, nullptr, 1, key});
    }

    void deallocate(Node* node) {
        node->r = free_list;
        free_list = node;
    }

    Node* merge(Node* l, Node* r) {
        if (!l || !r) {
            return l ? l : r;
        }
        if (rand() % (l->cnt + r->cnt) < l->cnt) {
            l->r = merge(l->r, r);
            l->cnt = (l->l ? l->l->cnt : 0) + (l->r ? l->r->cnt : 0) + 1;
            return l;
        } else {
            r->l = merge(l, r->l);
            r->cnt = (r->l ? r->l->cnt : 0) + (r->r ? r->r->cnt : 0) + 1;
            return r;
        }
    }

    pair<Node*, Node*> split(Node* t, int k) {
        if (!t) {
            return {nullptr, nullptr};
        }
        if (k <= (t->l ? t->l->cnt : 0)) {
            auto s = split(t->l, k);
            t->l = s.second;
            t->cnt = (t->l ? t->l->cnt : 0) + (t->r ? t->r->cnt : 0) + 1;
            return {s.first, t};
        } else {
            auto s = split(t->r, k - (t->l ? t->l->cnt : 0) - 1);
            t->r = s.first;
            t->cnt = (t->l ? t->l->cnt : 0) + (t->r ? t->r->cnt : 0) + 1;