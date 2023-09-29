#include <cstdio>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> tree;

void insert(int k) {
    tree[k] = true;
}

bool find(int k) {
    return tree[k];
}

void inorder() {
    for (auto it : tree) {
        if (it.second) {
            printf(" %d", it.first);
        }
    }
}

void preorder() {
    for (auto it : tree) {
        if (it.second) {
            printf(" %d", it.first);
        }
    }
}

int main() {
    int n, x;
    string com;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> com;
        if (com == "insert") {
            cin >> x;
            insert(x);
        } else if (com == "print") {
            inorder();
            cout << endl;
            preorder();
            cout << endl;
        } else if (com == "find") {
            cin >> x;
            if (find(x))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }

    return 0;
}