#include <unordered_map>
#include <memory>
#include <iostream>
using namespace std;

struct Node {
    int key;
    unique_ptr<Node> left, right;
};

unique_ptr<Node> root;
unordered_map<int, bool> keys;

void insert(int k) {
    unique_ptr<Node> y = nullptr;
    Node *x = root.get();
    auto z = make_unique<Node>();
    z->key = k;
    keys[k] = true;
    while (x != nullptr) {
        y = x;
        if (z->key < x->key) {
            x = x->left.get();
        } else {
            x = x->right.get();
        }
    }
    if (y == nullptr) {
        root = move(z);
    } else if (z->key < y->key) {
        y->left = move(z);
    } else {
        y->right = move(z);
    }
}

bool find(int k) {
    return keys[k];
}

void inorder(const Node *u) {
    if (u == nullptr)
        return;
    inorder(u->left.get());
    cout << ' ' << u->key;
    inorder(u->right.get());
}

void preorder(const Node *u) {
    if (u == nullptr)
        return;
    cout << ' ' << u->key;
    preorder(u->left.get());
    preorder(u->right.get());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    string com;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> com;
        if (com == "insert") {
            cin >> x;
            insert(x);
        } else if (com == "print") {
            inorder(root.get());
            cout << '\n';
            preorder(root.get());
            cout << '\n';
        } else if (com == "find") {
            cin >> x;
            if (find(x))
                cout << "yes\n";
            else
                cout << "no\n";
        }
    }
    return 0;
}