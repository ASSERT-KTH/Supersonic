#include <iostream>
#include <string>
using namespace std;

enum Command {
    Insert,
    Print
};

struct Node {
    int key;
    Node *right, *left, *parent;
};

Node *root, *nil;

void insert(int k) {
    Node *y = nil;
    Node *x = root;
    Node *z;
    z = new Node;
    z->key = k;
    z->left = nil;
    z->right = nil;
    while (x != nil) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == nil) {
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
    if (u == nil)
        return;
    inorder(u->left);
    cout << " " << u->key;
    inorder(u->right);
}

void preorder(Node *u) {
    if (u == nil)
        return;
    cout << " " << u->key;
    preorder(u->left);
    preorder(u->right);
}

int main() {
    int n, x;
    string com;
    cin >> n;
    for (auto i = 0; i < n; i++) {
        cin >> com;
        Command command = (com == "insert") ? Insert : Print;
        switch (command) {
            case Insert:
                cin >> x;
                insert(x);
                break;
            case Print:
                inorder(root);
                cout << "\n";
                preorder(root);
                cout << "\n";
                break;
        }
    }
    return 0;
}