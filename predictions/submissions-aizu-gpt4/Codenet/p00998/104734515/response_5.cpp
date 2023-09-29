#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

struct Node {
    int key, priority;
    int count, minimum;
    Node *left, *right;

    Node(int key): key(key), priority(rand()), count(1), minimum(key), left(nullptr), right(nullptr) {}
};

struct Treap {
    Node* root;

    Treap() : root(nullptr) {}

    int getCount(Node* node) {
        return node ? node->count : 0;
    }

    int getMinimum(Node* node) {
        return node ? node->minimum : INT_MAX;
    }

    Node* update(Node* node) {
        if (node) {
            node->count = getCount(node->left) + getCount(node->right) + 1;
            node->minimum = min({getMinimum(node->left), getMinimum(node->right), node->key});
        }
        return node;
    }

    Node* merge(Node* left, Node* right) {
        if (!left || !right) {
            return left ? left : right;
        }

        if (left->priority > right->priority) {
            left->right = merge(left->right, right);
            return update(left);
        }
        else {
            right->left = merge(left, right->left);
            return update(right);
        }
    }

    pair<Node*, Node*> split(Node* node, int k) {
        if (!node) {
            return make_pair(nullptr, nullptr);
        }

        if (k <= getCount(node->left)) {
            auto s = split(node->left, k);
            node->left = s.second;
            return make_pair(s.first, update(node));
        }
        else {
            auto s = split(node->right, k - getCount(node->left) - 1);
            node->right = s.first;
            return make_pair(update(node), s.second);
        }
    }

    void insert(int k, int key) {
        auto s = split(root, k);
        root = merge(merge(s.first, new Node(key)), s.second);
    }

    void erase(int k) {
        auto s1 = split(root, k + 1);
        auto s2 = split(s1.first, k);
        delete s2.second;
        root = merge(s2.first, s1.second);
    }

    int query(int l, int r) {
        auto s1 = split(root, r);
        auto s2 = split(s1.first, l);
        int ans = getMinimum(s2.second);
        root = merge(merge(s2.first, s2.second), s1.second);
        return ans;
    }

    void rotate(int l, int r) {
        auto s1 = split(root, r + 1);
        auto s2 = split(s1.first, r);
        auto s3 = split(s2.first, l);
        root = merge(merge(s3.first, s2.second), merge(s3.second, s1.second));
    }
};

int main() {
    srand(time(0));
    int n, q;
    cin >> n >> q;
    Treap treap;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        treap.insert(i, a);
    }
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 0) {
            treap.rotate(x, y);
        }
        else if (op == 1) {
            cout << treap.query(x, y + 1) << '\n';
        }
        else {
            treap.erase(x);
            treap.insert(x, y);
        }
    }
    return 0;
}