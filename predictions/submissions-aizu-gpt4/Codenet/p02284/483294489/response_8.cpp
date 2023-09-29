#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> tree_map;

void insert(int k) {
    tree_map[k] = true;
}

bool find(int k) {
    return tree_map[k];
}

void inorder() {
    for(auto i = tree_map.begin(); i != tree_map.end(); ++i)
        if(i->second)
            printf(" %d", i->first);
}

void preorder() {
    for(auto i = tree_map.begin(); i != tree_map.end(); ++i)
        if(i->second)
            printf(" %d", i->first);
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