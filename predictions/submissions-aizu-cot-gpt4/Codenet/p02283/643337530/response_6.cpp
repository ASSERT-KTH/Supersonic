#include <iostream>
#include <string>

struct Node {
    int key;
    Node *right, *left, *parent;

    Node(int k, Node* prnt = nullptr, Node* l = nullptr, Node* r = nullptr)
        : key(k), parent(prnt), left(l), right(r) {}
};

class BST {
private:
    Node* root, *NIL;
public:
    BST() : root(nullptr), NIL(nullptr) {}

    void insert(int k) {
        Node *y = NIL;
        Node *x = root;
        Node *z = new Node(k, NIL, NIL, NIL);

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

    Node* get_root() {
        return root;
    }
};

int main() {
    int n, i, x;
    std::string com;
    BST bst;
    std::cin >> n;

    for (i = 0; i < n; i++) {
        std::cin >> com;
        if (com == "insert") {
            std::cin >> x;
            bst.insert(x);
        } else if (com == "print") {
            bst.inorder(bst.get_root());
            std::cout << std::endl;
            bst.preorder(bst.get_root());
            std::cout << std::endl;
        }
    }
    return 0;
}