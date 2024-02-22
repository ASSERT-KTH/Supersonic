#include <iostream>

enum Command {
    INSERT,
    PRINT,
};

struct Node {
  int key;
  Node *right, *left, *parent;
};

class BinaryTree {
public:
    Node* root;
    Node* NIL;
    BinaryTree() : root(nullptr), NIL(nullptr) {}

    void insert(int k) {
        Node *y = NIL;
        Node *x = root;
        Node *z = new Node;
        z->key = k;
        z->left = NIL;
        z->right = NIL;
        while (x != NIL) {
            y = x;
            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        z->parent = y;
        if (y == NIL) {
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
        if (u == NIL)
            return;
        inorder(u->left);
        std::cout << " " << u->key;
        inorder(u->right);
    }

    void preorder(Node *u) {
        if (u == NIL)
            return;
        std::cout << " " << u->key;
        preorder(u->left);
        preorder(u->right);
    }
};

int main() {
    int n, i, x;
    Command com;

    std::cin >> n;
    BinaryTree tree;

    for (i = 0; i < n; i++) {
        std::cin >> com;
        switch (com) {
            case INSERT:
                std::cin >> x;
                tree.insert(x);
                break;
            case PRINT:
                tree.inorder(tree.root);
                std::cout << "\n";
                tree.preorder(tree.root);
                std::cout << "\n";
                break;
        }
    }
    return 0;
}