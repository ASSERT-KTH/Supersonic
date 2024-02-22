#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *right, *left, *parent;
};

Node *root = nullptr;

void insert(int k) {
    Node *y = nullptr;
    Node *x = root;
    Node *z = new Node;
    z->key = k;
    z->left = nullptr;
    z->right = nullptr;
    while (x != nullptr) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == nullptr) {
        root = z;
    } else {
        if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }
}

void inorder(Node *u) {
    if (u == nullptr)
        return;
    inorder(u->left);
    cout << " " << u->key;
    inorder(u->right);
}

void preorder(Node *u) {
    if (u == nullptr)
        return;
    cout << " " << u->key;
    preorder(u->left);
    preorder(u->right);
}

enum Command {
    INSERT,
    PRINT
};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int command;
        cin >> command;
        if (command == INSERT) {
            int x;
            cin >> x;
            insert(x);
        } else if (command == PRINT) {
            inorder(root);
            cout << "\n";
            preorder(root);
            cout << "\n";
        }
    }
    return 0;
}