#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    int key;
    Node *right, *left;
    Node(int key): key(key), right(nullptr), left(nullptr) {}
};

class BinaryTree {
    Node *root;

    void inorder(Node* u) {
        if (!u)
            return;
        inorder(u->left);
        cout << " " << u->key;
        inorder(u->right);
    }

    void preorder(Node* u) {
        if (!u)
            return;
        cout << " " << u->key;
        preorder(u->left);
        preorder(u->right);
    }

public:
    BinaryTree(): root(nullptr) {}

    void insert(int k) {
        Node* y = nullptr;
        Node* x = root;
        while (x != nullptr) {
            y = x;
            x = (k < x->key) ? x->left : x->right;
        }
        Node* z = new Node(k);
        if (y == nullptr) {
            root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }

    void print() {
        inorder(root);
        cout << "\n";
        preorder(root);
        cout << "\n";
    }
};

int main() {
    BinaryTree tree;
    int n, x;
    string com;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> com;
        if (com == "insert") {
            cin >> x;
            tree.insert(x);
        } else if (com == "print") {
            tree.print();
        }
    }
    return 0;
}