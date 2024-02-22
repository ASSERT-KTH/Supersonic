#include <iostream>
#include <sstream>
using namespace std;

enum Operation {
    INSERT,
    PRINT,
    FIND
};

struct Node {
    int key;
    Node* parent;
    Node* left;
    Node* right;
};

Node* root;
Node NIL;

void insert(int k) {
    Node* y = &NIL;
    Node* x = root;
    Node* z = new Node;
    z->key = k;
    z->left = &NIL;
    z->right = &NIL;

    while (x != &NIL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == &NIL) {
        root = z;
    } else {
        if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }
}

bool find(int k) {
    Node* x = root;
    while (x != &NIL) {
        if (k == x->key) {
            return true;
        }
        if (k < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return false;
}

void inorder(Node& u, stringstream& ss) {
    if (&u == &NIL) {
        return;
    }
    inorder(*u.left, ss);
    ss << " " << u.key;
    inorder(*u.right, ss);
}

void preorder(Node& u, stringstream& ss) {
    if (&u == &NIL) {
        return;
    }
    ss << " " << u.key;
    preorder(*u.left, ss);
    preorder(*u.right, ss);
}

int main() {
    int n, x;
    string com;
    cin >> n;

    NIL.key = -1;
    NIL.parent = &NIL;
    NIL.left = &NIL;
    NIL.right = &NIL;

    for (int i = 0; i < n; i++) {
        cin >> com;
        Operation op;
        if (com == "insert") {
            op = INSERT;
        } else if (com == "print") {
            op = PRINT;
        } else if (com == "find") {
            op = FIND;
        }

        switch (op) {
            case INSERT:
                cin >> x;
                insert(x);
                break;
            case PRINT: {
                stringstream ss;
                inorder(*root, ss);
                cout << ss.str() << endl;
                ss.str("");
                preorder(*root, ss);
                cout << ss.str() << endl;
                break;
            }
            case FIND:
                cin >> x;
                if (find(x)) {
                    cout << "yes" << endl;
                } else {
                    cout << "no" << endl;
                }
                break;
        }
    }

    return 0;
}