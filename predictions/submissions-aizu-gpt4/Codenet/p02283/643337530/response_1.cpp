#include <iostream>
#include <string>
using namespace std;

struct Node {
    int key;
    Node *right = nullptr, *left = nullptr;
};

Node* insert(Node* node, int key) {
    if (node == nullptr) {
        node = new Node;
        node->key = key;
    }
    else if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    
    return node;
}

void inorder(Node* node) {
    if (node == nullptr)
        return;
    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}

void preorder(Node* node) {
    if (node == nullptr)
        return;
    cout << node->key << " ";
    preorder(node->left);
    preorder(node->right);
}

int main() {
    Node* root = nullptr;
    int n, x;
    string command;
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> command;
        if (command == "insert") {
            cin >> x;
            root = insert(root, x);
        } else if (command == "print") {
            inorder(root);
            cout << "\n";
            preorder(root);
            cout << "\n";
        }
    }
    return 0;
}