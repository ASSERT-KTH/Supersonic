#include <iostream>
#include <memory>
#include <string>

struct Node {
    int key;
    Node *right = nullptr, *left = nullptr;
};

std::unique_ptr<Node> root;

void insert(int k) {
    std::unique_ptr<Node> z = std::make_unique<Node>();
    z->key = k;
    Node *y = nullptr;
    Node *x = root.get();

    while (x != nullptr) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    if (y == nullptr) {
        root = std::move(z);
    } else if (z->key < y->key) {
        y->left = z.release();
    } else {
        y->right = z.release();
    }
}

void inorder(Node *u) {
    if (u == nullptr)
        return;
    inorder(u->left);
    std::cout << " " << u->key;
    inorder(u->right);
}

void preorder(Node *u) {
    if (u == nullptr)
        return;
    std::cout << " " << u->key;
    preorder(u->left);
    preorder(u->right);
}

int main() {
    int n, x;
    std::string com;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> com;
        if (com == "insert") {
            std::cin >> x;
            insert(x);
        } else if (com == "print") {
            inorder(root.get());
            std::cout << "\n";
            preorder(root.get());
            std::cout << "\n";
        }
    }

    return 0;
}