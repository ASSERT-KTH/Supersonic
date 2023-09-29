#include <iostream>
#include <memory>
#include <string>

struct Node {
    int key;
    std::shared_ptr<Node> left, right;
};

std::shared_ptr<Node> root;

void insert(int k) {
    auto z = std::make_shared<Node>();
    z->key = k;
    if (root == nullptr) {
        root = z;
    } else {
        std::shared_ptr<Node> y = nullptr;
        auto x = root;
        while (x != nullptr) {
            y = x;
            x = (z->key < x->key) ? x->left : x->right;
        }
        if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }
}

void inorder(const std::shared_ptr<Node>& u) {
    if (u != nullptr) {
        inorder(u->left);
        std::cout << " " << u->key;
        inorder(u->right);
    }
}

void preorder(const std::shared_ptr<Node>& u) {
    if (u != nullptr) {
        std::cout << " " << u->key;
        preorder(u->left);
        preorder(u->right);
    }
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string command;
        std::cin >> command;
        if (command == "insert") {
            int x;
            std::cin >> x;
            insert(x);
        } else if (command == "print") {
            inorder(root);
            std::cout << "\n";
            preorder(root);
            std::cout << "\n";
        }
    }
    return 0;
}