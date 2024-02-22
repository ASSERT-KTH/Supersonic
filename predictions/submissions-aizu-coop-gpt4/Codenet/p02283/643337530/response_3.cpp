#include <iostream>
#include <memory>
#include <string>

class Node {
public:
    int key;
    std::shared_ptr<Node> left, right, parent;
};

class BST {
private:
    std::shared_ptr<Node> root;
    std::shared_ptr<Node> NIL;

public:
    void insert(int k) {
        std::shared_ptr<Node> y = NIL;
        std::shared_ptr<Node> x = root;
        auto z = std::make_shared<Node>();
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
    void inorder(std::shared_ptr<Node> u) {
        if (u == NIL)
            return;
        inorder(u->left);
        std::cout << " " << u->key;
        inorder(u->right);
    }
    void preorder(std::shared_ptr<Node> u) {
        if (u == NIL)
            return;
        std::cout << " " << u->key;
        preorder(u->left);
        preorder(u->right);
    }
    void print() {
        inorder(root);
        std::cout << "\n";
        preorder(root);
        std::cout << "\n";
    }
};

int main() {
    int n, x;
    std::string com;
    BST tree;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> com;
        if (com == "insert") {
            std::cin >> x;
            tree.insert(x);
        } else if (com == "print") {
            tree.print();
        }
    }
    return 0;
}